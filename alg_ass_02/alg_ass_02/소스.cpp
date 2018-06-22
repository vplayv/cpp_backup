#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>
struct d_Node{
	int data;
	struct d_Node * next;
	struct d_Node * prev;
};
typedef struct d_Node Node;
struct d_List
{
	struct d_Node * head;
	struct d_Node * tail;
	struct d_Node * mid;
	//Node * indexNode;
	int cnt;
};
typedef struct d_List Console;
struct d_Node_Flexible
{
	int List[];
};
typedef struct d_Node_Flexible tmpArray;
int list_cnt(Node * ptr);
Node* list_Insert_Head(Node * ptr);//머리쪽 생성
Node* list_Insert_Tail(Node * ptr);//꼬리쪽 생성
Node* list_Insert_Index(Node * ptr, int indexNum);//원하는 횟수번에 생성
Node* list_Delete_Head(Node * ptr);//머리쪽 제거
Node* list_Delete_Tail(Node * ptr);//꼬리쪽 제거
Node* list_Delete_Index(Node * ptr, int indexNum);//원하는 횟수번 삭제
Node* list_Delete_data(Node * ptr , int deleteInt);//원하는 데이터 삭제
void list_Search_Index(Node * ptr, int indexNum);//인덱스에 대한 노드 검사
void list_Search_data(Node * ptr, int searchInt);//데이터에 대한 노드검사
void list_Clear(Node * ptr); //모두 해방
Node* list_Copy(Node* ptr1, Node* ptr2); //모두 복사
Node* list_Sort_Asc(Node * ptr);//선택정렬로 함 오름차순( 점점 커짐)
Node* list_Sort_Dec(Node * ptr);//퀵 정렬로 함 내림차순( 점점 낮아짐)
void list_Sort_Dec_Quick(Node * head, Node * tail);//퀵 정렬
Node* list_Sort_Dec_Partition(Node* head, Node* tail);//퀵 정렬 파티션
void list_print(Node * ptr);//화면 출력용 함수
Node* list_Sort_Asc_Exchange(Node* ptr);//오름차순 교환정렬
Node* list_Sort_Asc_Merge(Node * ptr);

void array_mergeSort(int data[], int first, int n);
void array_merge(int data[], int first, int n1, int n2);
int main(){
	srand(time(NULL));
	Node* yesJam = NULL;
	Node* noJam = NULL;
	Console* yesJamConsole = NULL;
	LARGE_INTEGER startingTime, endingTime, elapsed;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&startingTime);
	QueryPerformanceCounter(&endingTime);
elapsed.QuadPart = endingTime.QuadPart - startingTime.QuadPart;

elapsed.QuadPart *= 1000000;
elapsed.QuadPart /= frequency.QuadPart;

printf("Elapsed Time(microseconds) : %I64d\n", elapsed);

		printf("\n");
		printf("================링크드 리스트==============");
		printf("\n");
		printf("0.list_print");
		printf("\n");
		printf("1.list_Insert_Head_ForN");
		printf("\n");
		printf("2.list_Clear");
		printf("\n");
		printf("12.list_Sort_Asc(Selection)");
		printf("\n");
		printf("13.list_Sort_Dec(Quick)");
		printf("\n");
		printf("14.list_Sort_Asc(Exchange)");
		printf("\n");
		printf("15.list_Sort_Asc(Merge)");
		printf("\n");
		printf("input Num : ");
	while(1){
		printf("\n");
		printf("================링크드 리스트==============");
		printf("\n");
		printf("input Num : ");
		int k;
		int input;
		int deleteInt;
		scanf_s("%d", &k);
		printf("\n");
		int N;
		printf("input N : ");
		scanf_s("%d", &N);
		printf("\n");
		DWORD start = GetTickCount();//시작
		QueryPerformanceCounter(&startingTime);//시작
		switch (k)
		{
		case 0:
			list_print(yesJam);
			break;
		case 1:
			for(int i = 0; i < N ;  i++)
			yesJam = list_Insert_Head(yesJam);
			break;
		case 2:
			list_Clear(yesJam);
			yesJam = NULL;
			break;
		case 12:
			printf("선택정렬 오름차순");
			yesJam = list_Sort_Asc(yesJam);
			break;
		case 13:
			printf("퀵정렬 내림차순");
			yesJam = list_Sort_Dec(yesJam);
			break;
		case 14:
			printf("교환정렬 오름차순");
			yesJam = list_Sort_Asc_Exchange(yesJam);
			break;
		case 15:
			printf("합병정렬 오름차순");
			yesJam = list_Sort_Asc_Merge(yesJam);
			break;
		default:
			break;
		}
			QueryPerformanceCounter(&endingTime);
	elapsed.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
	elapsed.QuadPart *= 1000000;
	elapsed.QuadPart /= frequency.QuadPart;
	printf("Elapsed Time(microseconds) : %I64d\n", elapsed);
	DWORD end = GetTickCount();//끝
	unsigned int result = end - start;
	printf("밀리 세컨드 : %lu\n", result);
	}
	return 0;

}
int list_cnt(Node* ptr){//노드의 갯수
	int count = 0;
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("리스트 카운터 호출 근데 ptr이 NULL 입니다. 리턴 0");
		return 0;
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		newConsole -> mid = newConsole -> head;
		while(newConsole -> mid -> next != NULL){
			newConsole -> mid = newConsole -> mid -> next;
			count++;
		}
		return count;//노드의 갯수 리턴
	}
}

Node* list_Insert_Head(Node * ptr){//링크드 리스트 맨 앞쪽에 노드 추가
	int randInt = rand() % 2001 -1000; //랜덤값
	Node* tmpNode = NULL; //임시
	if(ptr == NULL){//노드가 하나도 없을 경우
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{//노드가 하나라도 있을경우
		tmpNode = ptr;//임시 노드를 ptr의 링크드리스트를 지목하게 만든다.
		while(tmpNode -> prev != NULL){
			tmpNode = tmpNode -> prev;
		}
		tmpNode -> prev = (Node *)malloc(sizeof(Node));
		tmpNode -> prev ->next = tmpNode;//머리쪽에 노드 붙이기
		tmpNode = tmpNode -> prev;
		tmpNode -> data = randInt;
		tmpNode -> prev = NULL;//NULL로 초기화
		tmpNode = NULL;//free전 노드를 NULL로 지목한다.
	}
	free(tmpNode);
	return ptr;
}
Node* list_Insert_Tail(Node * ptr){//노드를 맨 뒤쪽에 추가하는 함수
	int randInt = rand() % 1000;//랜덤값
	Node* tmpNode = NULL;//임시 노드
	printf("꼬리 삽입 호출 rnd int = %d \n", randInt);
	if(ptr == NULL){//노드가 하나도 없을 경우
		printf("ptr이 NULL입니다. rnd int = %d", randInt);
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{
		printf("ptr이 NULL이 아닙니다. rnd int = %d", randInt);
		tmpNode = ptr;
		while(tmpNode -> next != NULL){
			tmpNode = tmpNode -> next;
		}
		tmpNode -> next = (Node *)malloc(sizeof(Node));
		tmpNode -> next -> prev = tmpNode;
		tmpNode -> next -> next = NULL;
		tmpNode = tmpNode -> next;
		tmpNode -> data = randInt;
		tmpNode -> next = NULL;
		tmpNode = NULL;
	}
	free(tmpNode);
	return ptr;
}
Node* list_Insert_Index(Node * ptr, int indexNum){//원하는 인덱스에 노드 삽입
	int randInt = rand() % 1000;
	Node* newNode;//임시 노드
	Console* newConsole;//노드 관리자
	newConsole = (Console *)malloc(sizeof(Console));
	printf("인덱스 삽입 호출 rnd int = %d \n", randInt);
	if(ptr == NULL){//노드가 하나도 없을때
		printf("ptr이 NULL입니다. rnd int = %d", randInt);
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr; //헤드 설정
		newConsole -> mid = newConsole -> head;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr; //꼬리 설정
		int countNum = list_cnt(newConsole -> mid);//노드의 총 갯수
		if(indexNum > countNum + 1)//인덱스가 콘솔의 갯수보다 더많음 리턴한다.
		{
			printf("인덱스가 너무 큽니다 종료합니다.");
			return ptr;
		}
		else if( indexNum == countNum + 1)//인덱스가 갯수+1 이라서 꼬리에 붙인다.
		{
			newNode = (Node *)malloc(sizeof(Node));
			newNode -> data = randInt;
			newNode -> prev = newConsole -> tail;
			newNode -> next = NULL;
			newConsole -> tail -> next = newNode;
			newConsole -> tail = newNode;
			
		}
		else//인덱스 < 카운트 일때
		{
			int i = 0;
			Node* beforeMid;
			newNode = (Node *)malloc(sizeof(Node));
			newNode -> data = randInt;
			while(i < indexNum)
			{
				newConsole -> mid = newConsole -> mid -> next;
				i++;// i 증가 mid를 원하는 위치로 옮기기 위해
			}
			beforeMid = newConsole -> mid -> prev;
			newNode -> next = newConsole -> mid;
			newNode -> prev = newConsole -> mid -> prev;
			newConsole -> mid -> prev = newNode;
			beforeMid -> next = newNode;
		}
	}
	newNode = NULL;
	newConsole = NULL;
	free(newNode);
	free(newConsole);
	return ptr;
}
Node* list_Delete_Head(Node * ptr){//맨 앞쪽 노드 제거
	Node* tmpNode;//임시 노드
	Console* newConsole;//노드 관리자
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){//노드가 없을 경우
		printf("ptr이 NULL입니다. 종료합니다");
	}
	else{//노드가 있을 경우
		printf("ptr이 NULL이 아닙니다.");
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		tmpNode = ptr;
		if(newConsole -> head -> next == NULL) //헤드노드 하나만 있을떄
		{
			newConsole -> head = NULL;
			ptr = NULL;
			tmpNode -> prev = NULL;
			tmpNode -> data = NULL;
			free(tmpNode);//노드 메모리 해제
			tmpNode = NULL;
		}
		else{// 그외 상황
			ptr = newConsole -> head -> next;
			newConsole -> head -> next = NULL;
			ptr -> prev = NULL;
			newConsole -> head = ptr;
			tmpNode -> data = NULL;
			free(tmpNode);//메모리 해제
			tmpNode = NULL;
		}
	}
	free(newConsole);
	return ptr;
}
Node* list_Delete_Tail(Node * ptr){
	Node* tmpNode;//임시 노드
	Console* newConsole;//노드 관리자
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr이 NULL입니다. 종료합니다");
	}
	else{
		printf("ptr이 NULL이 아닙니다.");
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		tmpNode = newConsole -> tail;
		if(newConsole -> head -> next == NULL) //헤드노드 하나만 있을떄
		{
			newConsole -> head = NULL;
			newConsole -> tail = NULL;
			ptr = NULL;
			tmpNode -> prev = NULL;
			tmpNode -> data = NULL;
			free(tmpNode);//노드 메모리 해제
			tmpNode = NULL;
		}
		else{// 그외 상황
			ptr = newConsole -> tail -> prev;
			newConsole -> tail-> prev= NULL;
			newConsole -> tail-> next= NULL;
			newConsole -> tail-> data= NULL;
			newConsole -> tail=ptr;
			ptr -> next = NULL;
			free(tmpNode);//메모리 해제
			tmpNode = NULL;
		}
	}
	free(newConsole);
	return ptr;
}
Node* list_Delete_Index(Node * ptr, int indexNum){//원하는 횟수번 삭제
	Console* newConsole;//노드 관리자
	newConsole = (Console *)malloc(sizeof(Console));
	printf("인덱스 삭제");
	if(ptr == NULL){
		printf("ptr이 NULL입니다.");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		newConsole -> mid = newConsole -> head;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		int countNum = list_cnt(newConsole -> mid);//노드의 갯수
		if(indexNum > countNum)//인덱스가 콘솔의 갯수보다 많으면 지울게 없다.
		{
			printf("인덱스가 너무 큽니다 종료합니다.");
			return ptr;
		}
		else if( indexNum == countNum)//인덱스 == 갯수 일때.
		{
			if(indexNum == 1)//머리 한개있는거 삭제
			{
				newConsole -> head = NULL;
				newConsole -> tail = NULL;
				newConsole -> mid = NULL;
				ptr = NULL;
			}
			else{ //꼬리삭제
				ptr = newConsole -> tail -> prev ;
				ptr -> next = NULL;
				newConsole -> tail -> prev = NULL;
				newConsole -> tail = ptr;

			}
		}
		else// 인덱스가 갯수보다 작을때
		{
			printf("인덱스 < 카운트");
			int i = 0;
			Node* beforeMid;
			Node* nextMid;
			while(i < indexNum)
			{
				newConsole -> mid = newConsole -> mid -> next;
				i++;// i 증가 mid를 원하는 위치로 옮기기 위해
			}
			beforeMid = newConsole -> mid -> prev;
			nextMid = newConsole -> mid -> next;
			beforeMid -> next = nextMid;
			nextMid -> prev = beforeMid;
			newConsole -> mid ->next= NULL;
			newConsole -> mid -> prev = NULL;
			free(newConsole -> mid); //문제 체크 필요할곳
			newConsole -> mid = beforeMid;
		}
	}
	return ptr;
}
Node* list_Delete_data(Node * ptr , int deleteInt){
	Console* newConsole;//노드 관리자
	Node * beforeMid;//임시 이전 노드
	newConsole = (Console *)malloc(sizeof(Console));
	printf("데이터 삭제");
	if(ptr == NULL){
		printf("ptr이 NULL입니다.");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		newConsole -> mid = newConsole -> head;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		ptr = newConsole -> head;
		int countNum = list_cnt(newConsole -> mid);
		while(newConsole -> mid -> next != NULL){//앞쪽으로 쭉 진행한다.
			if(newConsole -> mid -> data == deleteInt)//만약에 같을경우
			{
				if(newConsole -> mid -> prev == NULL){
					//헤드 일경우
					newConsole -> head = newConsole -> head -> next;
					ptr = newConsole -> head;
					free(newConsole -> mid);//앞쪽 해방
					newConsole -> mid = newConsole -> head;
				}
				else{//헤드가 아닐 경우
					beforeMid = newConsole -> mid -> prev;
					newConsole -> mid -> prev -> next = newConsole -> mid -> next; //뒤쪽을 앞쪽에 붙이고
					newConsole -> mid -> next -> prev = newConsole -> mid -> prev; //앞쪽을 뒤쪽에 붙이고
					newConsole -> mid -> prev = NULL;//뒤짜르고
					newConsole -> mid -> next = NULL;//앞짜르고
					free(newConsole -> mid);//메모리 해방시키고
					newConsole -> mid = beforeMid;//미드포인터를 위치를 설정
				}
			}
			newConsole -> mid = newConsole -> mid -> next;// 한칸씩 전진
		}
		if(newConsole -> mid -> next == NULL)
		{
			if(newConsole -> mid -> data ==deleteInt){//꼬리쪽에 데이터와 일치할 경우
				newConsole -> tail = newConsole -> tail -> prev; //꼬리 옮기고
				newConsole -> mid -> prev = NULL; //삭제할 데이터의 이전 링크 삭제
				newConsole -> tail -> next = NULL;//꼬리쪽 다음 링크 삭제
				free(newConsole -> mid);//데이터 해방
				newConsole -> mid = newConsole ->tail;//미드도 꼬리쪽 지목
			}
		}
	}
	return ptr;
}//원하는 데이터 삭제
void list_Search_Index(Node* ptr, int indexNum)//인덱스 위치의 데이터 검사
{
	Console* newConsole;//노드 관리자
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){//노드가 없을 경우
		printf("ptr이 NULL입니다.");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;//헤드 지정
		newConsole -> mid = newConsole -> head;//움직이는 미드 지정
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;//꼬리 지정
		int countNum = list_cnt(newConsole -> mid);//노드 총 갯수
		if(indexNum > countNum)//인덱스가 콘솔의 갯수보다 확인할수없다.
		{
			printf("인덱스가 너무 큽니다 종료합니다.");
			return ;
		}
		else//인덱스 <= 갯수 일때.
		{
			int i = 0;
			while(i <= indexNum)
			{
				if(i == indexNum){//찾았을경우
					int output = newConsole -> mid -> data;//인덱스의 데이터값
					printf("노드 출력값 : %d ", output);
					i++;
				}
				else{//아닐경우
					newConsole -> mid = newConsole -> mid -> next ;
					i++;
				}
			}
		}
	}
}
void list_Search_data(Node * ptr, int searchInt){//원하는 데이터가 존재하는지 찾기
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr이 NULL입니다.");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		newConsole -> mid = newConsole -> head;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		int countNum = list_cnt(newConsole -> mid);//노드의 총 갯수
		int i = 1;
		while(newConsole -> mid ->next != NULL){//mid 노드가 꼬리까지 while문으로 이동한다.
			if(newConsole -> mid -> data == searchInt){
				printf("발견하였습니다. %d번쨰 노드", i);//i번쨰 노드에서 발견
			}
			newConsole -> mid = newConsole -> mid -> next;//디음칸 이동
			i++; //노드 수 증가
		}
		if(newConsole -> tail -> data == searchInt){ //꼬리는 while문에서 발견안됌
			printf("발견하였습니다. %d 번째 노드", countNum);
		}
	}
}
void list_Clear(Node * ptr){
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr이 NULL입니다.");
		return ;
	}
	else
	{
		Node * tmpNode;//다음 노드
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		tmpNode = ptr;
		while(ptr -> next != NULL)//앞쪽부터 하나씩 제거한다.
		{
			ptr = ptr -> next;
			ptr -> prev = NULL;
			tmpNode ->next = NULL;
			tmpNode ->data = NULL;
			free(tmpNode);
			tmpNode = NULL;
			tmpNode = ptr;
		}
		if(ptr -> next == NULL)//마지막 노드를 제거
		{
			tmpNode = NULL;
			ptr ->data = NULL;
			ptr ->next = NULL;
			ptr ->prev = NULL;
			ptr = NULL;
		}
		free(tmpNode);

	}
}
Node* list_Copy(Node* ptr1, Node* ptr2){
	Console* newConsole1;//원본 콘솔
	newConsole1 = (Console *)malloc(sizeof(Console));
	Console* newConsole2;//복사할 대상 콘솔
	newConsole2 = (Console *)malloc(sizeof(Console));
	Node* newNode;//임시 노드 추가용
	
	if(ptr1 == NULL){
		printf("ptr1이 NULL입니다.");
}
	else
	{
		while(ptr1 -> prev != NULL){
			ptr1 = ptr1 -> prev;
		}
		newConsole1 -> head = ptr1;
		while(ptr1 -> next != NULL){
			ptr1 = ptr1 -> next;
		}
		newConsole1 -> tail = ptr1;
		newConsole1 -> mid = newConsole1 -> head;
		newNode = (Node *)malloc(sizeof(Node));//복사한 리스트의 헤드
		newNode -> data = newConsole1 -> head -> data;
		newNode -> prev = NULL;
		newNode -> next = NULL;
		ptr2 = newNode;//복사용 헤드 추가
		newConsole2 -> head = ptr2;
		newConsole2 -> mid = ptr2;
		while(newConsole1 -> mid -> next != NULL){
			newNode = NULL;
			newNode = (Node *)malloc(sizeof(Node));//메모리 할당
			newNode -> data = newConsole1 -> mid -> data;//데이터 복사
			newNode -> prev = NULL;
			newNode -> next = NULL;
			while(newConsole2 ->mid -> next != NULL){
				newConsole2 -> mid = newConsole2 -> mid -> next;
			}//콘솔2 미드를 꼬리로
			newConsole2 -> mid -> next = newNode;//꼬리에 붙이기
			newNode -> prev = newConsole2 -> mid;
			newConsole1 -> mid = newConsole1 -> mid -> next;//콘솔1 미드 한칸 뒤로
		}
		if(newConsole1 -> mid -> next == NULL){//원본의 끝에 왔을때
			newNode = NULL;
			newNode = (Node *)malloc(sizeof(Node));
			newNode -> prev = NULL;
			newNode -> next = NULL;
			newNode -> data = newConsole1 -> mid -> data;
			while(newConsole2 ->mid -> next != NULL){
				newConsole2 -> mid = newConsole2 -> mid -> next;
			}
			newConsole2 -> mid -> next = newNode;
			newNode -> prev = newConsole2 -> mid;
			newConsole1 -> mid = newConsole1 -> mid -> next;
		}
	}
	return ptr2;
}
Node* list_Sort_Asc(Node * ptr)//선택정렬로 함 오름차순( 점점 커짐)
{
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	Node* tmpNode;//임시 노드
	Node* saveNode = NULL;//위치 기억 노드
	if(ptr == NULL){
		printf("ptr이 NULL");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		newConsole -> mid = ptr;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		int countNum = list_cnt(newConsole -> mid); //총 갯수
		newConsole -> mid = newConsole ->head; //다시 원위치
		int position; // 첫위치 숫자
		int tmp;//저장용

		for(int i = 0 ; i < countNum ; i++){
			position = newConsole -> mid -> data; //포지션 저장
			tmpNode = newConsole -> mid;
			saveNode = newConsole -> mid;
			while(tmpNode-> next != NULL){
				tmp = tmpNode -> data;
				if(position > tmp){//tmp가 가장 작은놈이 됄때까지
					position = tmp;
					saveNode = tmpNode;
				}
				tmpNode = tmpNode -> next;
			}
			if(tmpNode -> next == NULL){//꼬리쪽 체크
				tmp = tmpNode -> data;
				if(position > tmp){//tmp가 가장 작은놈이 됄때까지
					position = tmp;
					saveNode = tmpNode;
				}
			}
			saveNode -> data = newConsole -> mid -> data;//tmp노드의 데이터를 포지션데이터를 집어놓고
			newConsole -> mid -> data = position;//대갈통 노드의 데이터에 가장 낮은 tmp를
			newConsole -> mid = newConsole -> mid ->next;//head는 한칸앞으로
			tmpNode = NULL;//tmp노드는 초기화
			saveNode = NULL;
		}
	}
	return ptr;
}
Node* list_Sort_Dec(Node * ptr){//퀵 정렬로 함 내림차순( 점점 낮아짐)
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr이 NULL");
	}
	else{
		while(ptr -> prev != NULL){ptr = ptr -> prev;}
		newConsole -> head = ptr;
		newConsole -> mid = ptr;
		while(ptr -> next != NULL){ptr = ptr -> next;}
		newConsole -> tail = ptr;
	}
	list_Sort_Dec_Quick(newConsole -> head, newConsole -> tail);//머리와 꼬리 설정한뒤 퀵정렬 시작
	return ptr;
}
void list_Sort_Dec_Quick(Node * head, Node * tail){//퀵 정렬
	if(!head || !tail)//헤드나 꼬리가 죽거나
		return ;
	if(head == tail)//헤드와 꼬리가 만나거나
		return ;
	Node * part = list_Sort_Dec_Partition(head, tail); //파티션
	Node * tmpNode1 = part -> prev , *tmpNode2 = part -> next;//데이터 바꾸기
	if(head == part)
		tmpNode1 = part;
	if(part == tail)
		tmpNode2 = part;
	list_Sort_Dec_Quick(head, tmpNode1);
	list_Sort_Dec_Quick(tmpNode2, tail);
}
Node* list_Sort_Dec_Partition(Node* head, Node* tail){//퀵 정렬 파티션
	Node* start = head; //스타트 노드
    int pivot = head->data; //피봇
    int flag = 0;//참 거짓 용

    while(!flag)
    {
        while(head && head->data<=pivot)
        {
			head = head->next;
            if(head == tail)
                flag = 1;
        }
        while(tail && tail->data>pivot)
        {
			tail = tail->prev;
            if(head == tail)
                flag = 1;
        }
        if(!flag)
        {
            int temp = head->data;
            head->data = tail->data;
            tail->data = temp;
        }
    }
    //데이터 스왑
    int temp = tail->data;
    tail->data = start->data;
    start->data = temp;
    return tail;
}
Node* list_Sort_Asc_Exchange(Node* ptr){//오름차순 교환정렬
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	Node* tmpNode;//임시 노드
	if(ptr == NULL){
		printf("ptr이 NULL");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;//헤드
		newConsole -> mid = ptr;//미드
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;//꼬리
		int countNum = list_cnt(newConsole -> mid); //총 갯수
		newConsole -> mid = newConsole ->head; //다시 원위치
		int tmp;//저장용
		for(int i = 0 ; i < countNum ; i++){
			tmpNode = newConsole -> mid -> next;
			while(tmpNode-> next != NULL){
				tmp = tmpNode -> data;
				if(newConsole -> mid -> data > tmp){//tmp가 가장 작은놈이 됄때까지
					tmpNode -> data = newConsole ->mid -> data;//즉시 데이터 교환
					newConsole -> mid -> data = tmp;//즉시 데이터 교환2
				}
				tmpNode = tmpNode -> next;
			}
			if(tmpNode -> next == NULL){//꼬리쪽 체크
				tmp = tmpNode -> data;
				if(newConsole -> mid -> data > tmp){//tmp가 가장 작은놈이 됄때까지
					tmpNode -> data = newConsole ->mid -> data;
					newConsole -> mid -> data = tmp;
				}
				newConsole -> mid = newConsole -> mid ->next;//head는 한칸앞으로
				tmpNode = NULL;//tmp노드는 초기화
			}
		}
		newConsole = NULL;
		free(newConsole);
		tmpNode = NULL;
		free(tmpNode);
	return ptr;
	}
}
void list_print(Node * ptr){//노드의 연결 상태를 확인하는 함수
	Node* tmpNode;
	if(ptr == NULL){
		printf("ptr이 NULL");
	}
	else{
		tmpNode = ptr;
		while(tmpNode -> prev != NULL){
			tmpNode = tmpNode -> prev;
		}
		while(tmpNode -> next != NULL){
			printf("%d -> ", tmpNode -> data);
			tmpNode = tmpNode -> next;
		}
		if(tmpNode -> next ==NULL){
			printf("%d -> NULL", tmpNode -> data);
		}
	}
}
Node* list_Sort_Asc_Merge(Node * ptr){
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr이 NULL");
	}
	else{
		while(ptr -> prev != NULL){ptr = ptr -> prev;}
		newConsole -> head = ptr;
		newConsole -> mid = ptr;
		while(ptr -> next != NULL){ptr = ptr -> next;}
		newConsole -> tail = ptr;
	}
	int arraySize =  list_cnt(ptr);//사이즈
	tmpArray * myArray;//플렉시블 임시 배열
	int mallocSize = sizeof(tmpArray) + sizeof(int)*(arraySize+1);
	myArray = (tmpArray *)malloc(mallocSize);//크기 할당
	for(int i = 0; i < arraySize ; i ++){
		myArray -> List[i] = newConsole -> mid -> data; //데이터 놓고
		newConsole -> mid = newConsole -> mid ->next;
	}
	newConsole -> mid = newConsole -> head;
	array_mergeSort(myArray -> List , 0, arraySize);//합명 정렬 시작
	for(int j = 0; j < arraySize ; j ++){
		newConsole -> mid -> data = myArray -> List[j];//데이터 집어놓고,
		newConsole -> mid = newConsole -> mid ->next;
	}
	free(myArray);
	myArray = NULL;
	return ptr;
}
void array_mergeSort(int data[], int first, int n){
	int n1;
	int n2;
	if( n >1 ){
		n1 = n / 2;
		n2 = n - n1;
		
		array_mergeSort(data, first, n1);
		array_mergeSort(data, first+n1, n2);

		array_merge(data, first, n1, n2);
	} 
}
void array_merge(int data[], int first, int n1, int n2){
	tmpArray * myArray2;//플렉시블 임시 배열
	int x = n1 + n2;
	myArray2 = (tmpArray *)malloc(sizeof(tmpArray) + sizeof(int)*x);//크기 할당
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;
	int i;
	while((copied1 < n1) && (copied2 < n2)){
		if(data[first + copied1] < data[first + n1 + copied2])
			myArray2 -> List[copied++] = data[first + (copied1++)];
		else
			myArray2 -> List[copied++] = data[first + n1 + (copied2++)];
	}
	while(copied1 < n1)
		myArray2 -> List[copied++] = data[first + (copied1++)];
	for(i = 0; i < copied; i++)
		data[first + i] = myArray2 -> List[i];
	free(myArray2);
	myArray2 = NULL;
}