#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>//기존에 있는 스택 헤더를 이용함
#include <string>
using namespace std;
double read_and_evaluate(istream& ins);//읽고 계산
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);//스택 탑 계산
int mod (int a, int b);//나머지
void convertingExpression(char myArray[]);//후위로 변환
char myArray[100];//입력스트림 버퍼 저장용
int main(){
	double answer;

	std::cout<<"INFIX 산술식 입력(2번 해야합니다 프로그램 잘못 짜서..) : ";//입력
	answer = read_and_evaluate(std::cin.getline(myArray,100));//입력 두번 해야함, 입력스트림을 잘못짜서
	std::cout<<"정답 : "<<answer<<endl;
	convertingExpression(myArray);
	return 0;
}
double read_and_evaluate(istream& ins){//입력 스트림 참조자
	const char DECIMAL = '.';//소수점용
	const char RIGHT_PARENTHESIS = ')';//오른쪽 괄호
	stack<double> numbers;//스택
	stack<char> operations;//스택
	double number;
	char symbol;//오퍼레이터 확인
	numbers.push(0);
	string error="ERROR"; 
	try{
	while(ins && ins.peek() != '\n'){
		if(isdigit(ins.peek()) || (ins.peek() == DECIMAL )){
			ins >> number;
			numbers.push(number);
		}
		else if(strchr("+-*/^%", ins.peek()) != NULL){//입력스트림 한개를 오퍼레이터에 체크
			ins >> symbol;
			operations.push(symbol);
		}
		else if(ins.peek() == RIGHT_PARENTHESIS){
			ins.ignore();//무시하고 버퍼에서 삭제
			evaluate_stack_tops(numbers, operations);//그리고 계산
		}
		else if(numbers.size() >=2 && operations.size() >=1)
			evaluate_stack_tops(numbers, operations);//갯수 넘을때 계산
		else
			ins.ignore();//그이외 버퍼 무시
		if((operations.size() >= numbers.size()) && (operations.size() >= 2))
		{cout<<"ERROR"<<endl; return -9999.999;} //에러
	}
	
	while(numbers.size() >=2 && operations.size() >=1)
		evaluate_stack_tops(numbers, operations);//스택 처리
	}
	catch(exception e){
		cout<<"ERROR"<<endl;
		throw error;
		return -9999.99;
	}
	return numbers.top();
}
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations){
	double o1 = 0, o2 = 0;
	o2 = numbers.top();//탑에서 뺀다.
	numbers.pop();
	o1 = numbers.top();//탑에서 뺀다.
	numbers.pop();
	int k = o1;
	int l = 0;
	try{
		switch (operations.top()){//오퍼레이터 계산
	case '+':
		numbers.push(o1 + o2);
		break;
	case '-':
		numbers.push(o1 - o2);
		break;
	case '*':
		numbers.push(o1 * o2);
		break;
	case '/':
		numbers.push(o1 / o2);
		break;
	case '^':
		for(int i = 0 ; i < o2 -1 ; i++)
		{
			o1 = o1 * k;
		}
		numbers.push(o1);
	case '%':
		l = mod(o1, o2);//모듈은 따로 함수 구현해서 계산
		numbers.push(l);
	default:
		break;
		}
	}
	catch(exception e){
		  string error="ERROR";
		  throw error; 
	}
	operations.pop();
}
int mod (int a, int b)//모듈 함수
{
   if(b < 0) 
     return mod(-a, -b);   
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
void convertingExpression(char myArray[]){//변환 함수
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	stack<char> store;//오퍼레이터용 스택
	string::size_type i;
	char expression[100] = {'\0'}; // 후위
	int arrayNumber = 0;//중위용
	int expressNumber = 0;//후위용
	do{
		if(myArray[arrayNumber] == LEFT_PARENTHESIS){//왼쪽 괄호 푸쉬
			store.push(myArray[arrayNumber]);
			arrayNumber++;
		}
		else if((myArray[arrayNumber] == '0') || (myArray[arrayNumber] == '1') || (myArray[arrayNumber] == '2') || (myArray[arrayNumber] == '3')
			|| (myArray[arrayNumber] == '4') || (myArray[arrayNumber] == '5') || (myArray[arrayNumber] == '6') || (myArray[arrayNumber] == '7')
			|| (myArray[arrayNumber] == '8') || (myArray[arrayNumber] == '9')){
				expression[expressNumber] = myArray[arrayNumber];//숫자는 후위로 바로 투입
				arrayNumber++;
				expressNumber++;
		}
		else if((myArray[arrayNumber] == '+' )|| (myArray[arrayNumber] == '-' ) || (myArray[arrayNumber] == '*'|| (myArray[arrayNumber] == '/' )
			|| (myArray[arrayNumber] == '%' )|| (myArray[arrayNumber] == '^' ) )){//오퍼레이터 체크

				while(store.size() != 0 || (myArray[arrayNumber + 1] == LEFT_PARENTHESIS)){//만약 안에 있거나 괄호 있을경우 스택을 비운다.
					expression[expressNumber] = store.top();
					expressNumber++;
				store.pop();
				}
			store.push(myArray[arrayNumber]);//푸쉬
			arrayNumber++;
		}
		else{
			if(myArray[arrayNumber] == RIGHT_PARENTHESIS){//오른쪽 괄호일때
				while( store.top() != LEFT_PARENTHESIS){//왼쪽괄호 나올때까지 스택 처리
					expression[expressNumber] = store.top();
					store.pop();
					arrayNumber++;
					expressNumber++;
				}
				if(store.top() == LEFT_PARENTHESIS)//왼쪽괄호 처리
					store.pop();
			}
			if(myArray[arrayNumber] == ' '){//공백
				expression[expressNumber]  = ' ';
				expressNumber++;
				arrayNumber++;
			}
		}
	}
	while(myArray[arrayNumber] != '\0');//널 문자 있을때까지 do-while
	expression[expressNumber] = store.top();//무조건 스택 하나가 남아서 추가함
	store.pop();//마무리 팝
	cout<<"POSTFIX : "<<expression<<endl;//결과
}
