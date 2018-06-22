#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>//������ �ִ� ���� ����� �̿���
#include <string>
using namespace std;
double read_and_evaluate(istream& ins);//�а� ���
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations);//���� ž ���
int mod (int a, int b);//������
void convertingExpression(char myArray[]);//������ ��ȯ
char myArray[100];//�Է½�Ʈ�� ���� �����
int main(){
	double answer;

	std::cout<<"INFIX ����� �Է�(2�� �ؾ��մϴ� ���α׷� �߸� ¥��..) : ";//�Է�
	answer = read_and_evaluate(std::cin.getline(myArray,100));//�Է� �ι� �ؾ���, �Է½�Ʈ���� �߸�¥��
	std::cout<<"���� : "<<answer<<endl;
	convertingExpression(myArray);
	return 0;
}
double read_and_evaluate(istream& ins){//�Է� ��Ʈ�� ������
	const char DECIMAL = '.';//�Ҽ�����
	const char RIGHT_PARENTHESIS = ')';//������ ��ȣ
	stack<double> numbers;//����
	stack<char> operations;//����
	double number;
	char symbol;//���۷����� Ȯ��
	numbers.push(0);
	string error="ERROR"; 
	try{
	while(ins && ins.peek() != '\n'){
		if(isdigit(ins.peek()) || (ins.peek() == DECIMAL )){
			ins >> number;
			numbers.push(number);
		}
		else if(strchr("+-*/^%", ins.peek()) != NULL){//�Է½�Ʈ�� �Ѱ��� ���۷����Ϳ� üũ
			ins >> symbol;
			operations.push(symbol);
		}
		else if(ins.peek() == RIGHT_PARENTHESIS){
			ins.ignore();//�����ϰ� ���ۿ��� ����
			evaluate_stack_tops(numbers, operations);//�׸��� ���
		}
		else if(numbers.size() >=2 && operations.size() >=1)
			evaluate_stack_tops(numbers, operations);//���� ������ ���
		else
			ins.ignore();//���̿� ���� ����
		if((operations.size() >= numbers.size()) && (operations.size() >= 2))
		{cout<<"ERROR"<<endl; return -9999.999;} //����
	}
	
	while(numbers.size() >=2 && operations.size() >=1)
		evaluate_stack_tops(numbers, operations);//���� ó��
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
	o2 = numbers.top();//ž���� ����.
	numbers.pop();
	o1 = numbers.top();//ž���� ����.
	numbers.pop();
	int k = o1;
	int l = 0;
	try{
		switch (operations.top()){//���۷����� ���
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
		l = mod(o1, o2);//����� ���� �Լ� �����ؼ� ���
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
int mod (int a, int b)//��� �Լ�
{
   if(b < 0) 
     return mod(-a, -b);   
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
void convertingExpression(char myArray[]){//��ȯ �Լ�
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	stack<char> store;//���۷����Ϳ� ����
	string::size_type i;
	char expression[100] = {'\0'}; // ����
	int arrayNumber = 0;//������
	int expressNumber = 0;//������
	do{
		if(myArray[arrayNumber] == LEFT_PARENTHESIS){//���� ��ȣ Ǫ��
			store.push(myArray[arrayNumber]);
			arrayNumber++;
		}
		else if((myArray[arrayNumber] == '0') || (myArray[arrayNumber] == '1') || (myArray[arrayNumber] == '2') || (myArray[arrayNumber] == '3')
			|| (myArray[arrayNumber] == '4') || (myArray[arrayNumber] == '5') || (myArray[arrayNumber] == '6') || (myArray[arrayNumber] == '7')
			|| (myArray[arrayNumber] == '8') || (myArray[arrayNumber] == '9')){
				expression[expressNumber] = myArray[arrayNumber];//���ڴ� ������ �ٷ� ����
				arrayNumber++;
				expressNumber++;
		}
		else if((myArray[arrayNumber] == '+' )|| (myArray[arrayNumber] == '-' ) || (myArray[arrayNumber] == '*'|| (myArray[arrayNumber] == '/' )
			|| (myArray[arrayNumber] == '%' )|| (myArray[arrayNumber] == '^' ) )){//���۷����� üũ

				while(store.size() != 0 || (myArray[arrayNumber + 1] == LEFT_PARENTHESIS)){//���� �ȿ� �ְų� ��ȣ ������� ������ ����.
					expression[expressNumber] = store.top();
					expressNumber++;
				store.pop();
				}
			store.push(myArray[arrayNumber]);//Ǫ��
			arrayNumber++;
		}
		else{
			if(myArray[arrayNumber] == RIGHT_PARENTHESIS){//������ ��ȣ�϶�
				while( store.top() != LEFT_PARENTHESIS){//���ʰ�ȣ ���ö����� ���� ó��
					expression[expressNumber] = store.top();
					store.pop();
					arrayNumber++;
					expressNumber++;
				}
				if(store.top() == LEFT_PARENTHESIS)//���ʰ�ȣ ó��
					store.pop();
			}
			if(myArray[arrayNumber] == ' '){//����
				expression[expressNumber]  = ' ';
				expressNumber++;
				arrayNumber++;
			}
		}
	}
	while(myArray[arrayNumber] != '\0');//�� ���� ���������� do-while
	expression[expressNumber] = store.top();//������ ���� �ϳ��� ���Ƽ� �߰���
	store.pop();//������ ��
	cout<<"POSTFIX : "<<expression<<endl;//���
}
