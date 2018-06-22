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
Node* list_Insert_Head(Node * ptr);//�Ӹ��� ����
Node* list_Insert_Tail(Node * ptr);//������ ����
Node* list_Insert_Index(Node * ptr, int indexNum);//���ϴ� Ƚ������ ����
Node* list_Delete_Head(Node * ptr);//�Ӹ��� ����
Node* list_Delete_Tail(Node * ptr);//������ ����
Node* list_Delete_Index(Node * ptr, int indexNum);//���ϴ� Ƚ���� ����
Node* list_Delete_data(Node * ptr , int deleteInt);//���ϴ� ������ ����
void list_Search_Index(Node * ptr, int indexNum);//�ε����� ���� ��� �˻�
void list_Search_data(Node * ptr, int searchInt);//�����Ϳ� ���� ���˻�
void list_Clear(Node * ptr); //��� �ع�
Node* list_Copy(Node* ptr1, Node* ptr2); //��� ����
Node* list_Sort_Asc(Node * ptr);//�������ķ� �� ��������( ���� Ŀ��)
Node* list_Sort_Dec(Node * ptr);//�� ���ķ� �� ��������( ���� ������)
void list_Sort_Dec_Quick(Node * head, Node * tail);//�� ����
Node* list_Sort_Dec_Partition(Node* head, Node* tail);//�� ���� ��Ƽ��
void list_print(Node * ptr);//ȭ�� ��¿� �Լ�
Node* list_Sort_Asc_Exchange(Node* ptr);//�������� ��ȯ����
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
		printf("================��ũ�� ����Ʈ==============");
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
		printf("================��ũ�� ����Ʈ==============");
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
		DWORD start = GetTickCount();//����
		QueryPerformanceCounter(&startingTime);//����
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
			printf("�������� ��������");
			yesJam = list_Sort_Asc(yesJam);
			break;
		case 13:
			printf("������ ��������");
			yesJam = list_Sort_Dec(yesJam);
			break;
		case 14:
			printf("��ȯ���� ��������");
			yesJam = list_Sort_Asc_Exchange(yesJam);
			break;
		case 15:
			printf("�պ����� ��������");
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
	DWORD end = GetTickCount();//��
	unsigned int result = end - start;
	printf("�и� ������ : %lu\n", result);
	}
	return 0;

}
int list_cnt(Node* ptr){//����� ����
	int count = 0;
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("����Ʈ ī���� ȣ�� �ٵ� ptr�� NULL �Դϴ�. ���� 0");
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
		return count;//����� ���� ����
	}
}

Node* list_Insert_Head(Node * ptr){//��ũ�� ����Ʈ �� ���ʿ� ��� �߰�
	int randInt = rand() % 2001 -1000; //������
	Node* tmpNode = NULL; //�ӽ�
	if(ptr == NULL){//��尡 �ϳ��� ���� ���
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{//��尡 �ϳ��� �������
		tmpNode = ptr;//�ӽ� ��带 ptr�� ��ũ�帮��Ʈ�� �����ϰ� �����.
		while(tmpNode -> prev != NULL){
			tmpNode = tmpNode -> prev;
		}
		tmpNode -> prev = (Node *)malloc(sizeof(Node));
		tmpNode -> prev ->next = tmpNode;//�Ӹ��ʿ� ��� ���̱�
		tmpNode = tmpNode -> prev;
		tmpNode -> data = randInt;
		tmpNode -> prev = NULL;//NULL�� �ʱ�ȭ
		tmpNode = NULL;//free�� ��带 NULL�� �����Ѵ�.
	}
	free(tmpNode);
	return ptr;
}
Node* list_Insert_Tail(Node * ptr){//��带 �� ���ʿ� �߰��ϴ� �Լ�
	int randInt = rand() % 1000;//������
	Node* tmpNode = NULL;//�ӽ� ���
	printf("���� ���� ȣ�� rnd int = %d \n", randInt);
	if(ptr == NULL){//��尡 �ϳ��� ���� ���
		printf("ptr�� NULL�Դϴ�. rnd int = %d", randInt);
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{
		printf("ptr�� NULL�� �ƴմϴ�. rnd int = %d", randInt);
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
Node* list_Insert_Index(Node * ptr, int indexNum){//���ϴ� �ε����� ��� ����
	int randInt = rand() % 1000;
	Node* newNode;//�ӽ� ���
	Console* newConsole;//��� ������
	newConsole = (Console *)malloc(sizeof(Console));
	printf("�ε��� ���� ȣ�� rnd int = %d \n", randInt);
	if(ptr == NULL){//��尡 �ϳ��� ������
		printf("ptr�� NULL�Դϴ�. rnd int = %d", randInt);
		ptr = (Node *)malloc(sizeof(Node));
		ptr -> data = randInt;
		ptr -> next = NULL;
		ptr -> prev = NULL;
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr; //��� ����
		newConsole -> mid = newConsole -> head;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr; //���� ����
		int countNum = list_cnt(newConsole -> mid);//����� �� ����
		if(indexNum > countNum + 1)//�ε����� �ܼ��� �������� ������ �����Ѵ�.
		{
			printf("�ε����� �ʹ� Ů�ϴ� �����մϴ�.");
			return ptr;
		}
		else if( indexNum == countNum + 1)//�ε����� ����+1 �̶� ������ ���δ�.
		{
			newNode = (Node *)malloc(sizeof(Node));
			newNode -> data = randInt;
			newNode -> prev = newConsole -> tail;
			newNode -> next = NULL;
			newConsole -> tail -> next = newNode;
			newConsole -> tail = newNode;
			
		}
		else//�ε��� < ī��Ʈ �϶�
		{
			int i = 0;
			Node* beforeMid;
			newNode = (Node *)malloc(sizeof(Node));
			newNode -> data = randInt;
			while(i < indexNum)
			{
				newConsole -> mid = newConsole -> mid -> next;
				i++;// i ���� mid�� ���ϴ� ��ġ�� �ű�� ����
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
Node* list_Delete_Head(Node * ptr){//�� ���� ��� ����
	Node* tmpNode;//�ӽ� ���
	Console* newConsole;//��� ������
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){//��尡 ���� ���
		printf("ptr�� NULL�Դϴ�. �����մϴ�");
	}
	else{//��尡 ���� ���
		printf("ptr�� NULL�� �ƴմϴ�.");
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		tmpNode = ptr;
		if(newConsole -> head -> next == NULL) //����� �ϳ��� ������
		{
			newConsole -> head = NULL;
			ptr = NULL;
			tmpNode -> prev = NULL;
			tmpNode -> data = NULL;
			free(tmpNode);//��� �޸� ����
			tmpNode = NULL;
		}
		else{// �׿� ��Ȳ
			ptr = newConsole -> head -> next;
			newConsole -> head -> next = NULL;
			ptr -> prev = NULL;
			newConsole -> head = ptr;
			tmpNode -> data = NULL;
			free(tmpNode);//�޸� ����
			tmpNode = NULL;
		}
	}
	free(newConsole);
	return ptr;
}
Node* list_Delete_Tail(Node * ptr){
	Node* tmpNode;//�ӽ� ���
	Console* newConsole;//��� ������
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr�� NULL�Դϴ�. �����մϴ�");
	}
	else{
		printf("ptr�� NULL�� �ƴմϴ�.");
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;
		tmpNode = newConsole -> tail;
		if(newConsole -> head -> next == NULL) //����� �ϳ��� ������
		{
			newConsole -> head = NULL;
			newConsole -> tail = NULL;
			ptr = NULL;
			tmpNode -> prev = NULL;
			tmpNode -> data = NULL;
			free(tmpNode);//��� �޸� ����
			tmpNode = NULL;
		}
		else{// �׿� ��Ȳ
			ptr = newConsole -> tail -> prev;
			newConsole -> tail-> prev= NULL;
			newConsole -> tail-> next= NULL;
			newConsole -> tail-> data= NULL;
			newConsole -> tail=ptr;
			ptr -> next = NULL;
			free(tmpNode);//�޸� ����
			tmpNode = NULL;
		}
	}
	free(newConsole);
	return ptr;
}
Node* list_Delete_Index(Node * ptr, int indexNum){//���ϴ� Ƚ���� ����
	Console* newConsole;//��� ������
	newConsole = (Console *)malloc(sizeof(Console));
	printf("�ε��� ����");
	if(ptr == NULL){
		printf("ptr�� NULL�Դϴ�.");
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
		int countNum = list_cnt(newConsole -> mid);//����� ����
		if(indexNum > countNum)//�ε����� �ܼ��� �������� ������ ����� ����.
		{
			printf("�ε����� �ʹ� Ů�ϴ� �����մϴ�.");
			return ptr;
		}
		else if( indexNum == countNum)//�ε��� == ���� �϶�.
		{
			if(indexNum == 1)//�Ӹ� �Ѱ��ִ°� ����
			{
				newConsole -> head = NULL;
				newConsole -> tail = NULL;
				newConsole -> mid = NULL;
				ptr = NULL;
			}
			else{ //��������
				ptr = newConsole -> tail -> prev ;
				ptr -> next = NULL;
				newConsole -> tail -> prev = NULL;
				newConsole -> tail = ptr;

			}
		}
		else// �ε����� �������� ������
		{
			printf("�ε��� < ī��Ʈ");
			int i = 0;
			Node* beforeMid;
			Node* nextMid;
			while(i < indexNum)
			{
				newConsole -> mid = newConsole -> mid -> next;
				i++;// i ���� mid�� ���ϴ� ��ġ�� �ű�� ����
			}
			beforeMid = newConsole -> mid -> prev;
			nextMid = newConsole -> mid -> next;
			beforeMid -> next = nextMid;
			nextMid -> prev = beforeMid;
			newConsole -> mid ->next= NULL;
			newConsole -> mid -> prev = NULL;
			free(newConsole -> mid); //���� üũ �ʿ��Ұ�
			newConsole -> mid = beforeMid;
		}
	}
	return ptr;
}
Node* list_Delete_data(Node * ptr , int deleteInt){
	Console* newConsole;//��� ������
	Node * beforeMid;//�ӽ� ���� ���
	newConsole = (Console *)malloc(sizeof(Console));
	printf("������ ����");
	if(ptr == NULL){
		printf("ptr�� NULL�Դϴ�.");
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
		while(newConsole -> mid -> next != NULL){//�������� �� �����Ѵ�.
			if(newConsole -> mid -> data == deleteInt)//���࿡ �������
			{
				if(newConsole -> mid -> prev == NULL){
					//��� �ϰ��
					newConsole -> head = newConsole -> head -> next;
					ptr = newConsole -> head;
					free(newConsole -> mid);//���� �ع�
					newConsole -> mid = newConsole -> head;
				}
				else{//��尡 �ƴ� ���
					beforeMid = newConsole -> mid -> prev;
					newConsole -> mid -> prev -> next = newConsole -> mid -> next; //������ ���ʿ� ���̰�
					newConsole -> mid -> next -> prev = newConsole -> mid -> prev; //������ ���ʿ� ���̰�
					newConsole -> mid -> prev = NULL;//��¥����
					newConsole -> mid -> next = NULL;//��¥����
					free(newConsole -> mid);//�޸� �ع��Ű��
					newConsole -> mid = beforeMid;//�̵������͸� ��ġ�� ����
				}
			}
			newConsole -> mid = newConsole -> mid -> next;// ��ĭ�� ����
		}
		if(newConsole -> mid -> next == NULL)
		{
			if(newConsole -> mid -> data ==deleteInt){//�����ʿ� �����Ϳ� ��ġ�� ���
				newConsole -> tail = newConsole -> tail -> prev; //���� �ű��
				newConsole -> mid -> prev = NULL; //������ �������� ���� ��ũ ����
				newConsole -> tail -> next = NULL;//������ ���� ��ũ ����
				free(newConsole -> mid);//������ �ع�
				newConsole -> mid = newConsole ->tail;//�̵嵵 ������ ����
			}
		}
	}
	return ptr;
}//���ϴ� ������ ����
void list_Search_Index(Node* ptr, int indexNum)//�ε��� ��ġ�� ������ �˻�
{
	Console* newConsole;//��� ������
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){//��尡 ���� ���
		printf("ptr�� NULL�Դϴ�.");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;//��� ����
		newConsole -> mid = newConsole -> head;//�����̴� �̵� ����
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;//���� ����
		int countNum = list_cnt(newConsole -> mid);//��� �� ����
		if(indexNum > countNum)//�ε����� �ܼ��� �������� Ȯ���Ҽ�����.
		{
			printf("�ε����� �ʹ� Ů�ϴ� �����մϴ�.");
			return ;
		}
		else//�ε��� <= ���� �϶�.
		{
			int i = 0;
			while(i <= indexNum)
			{
				if(i == indexNum){//ã�������
					int output = newConsole -> mid -> data;//�ε����� �����Ͱ�
					printf("��� ��°� : %d ", output);
					i++;
				}
				else{//�ƴҰ��
					newConsole -> mid = newConsole -> mid -> next ;
					i++;
				}
			}
		}
	}
}
void list_Search_data(Node * ptr, int searchInt){//���ϴ� �����Ͱ� �����ϴ��� ã��
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr�� NULL�Դϴ�.");
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
		int countNum = list_cnt(newConsole -> mid);//����� �� ����
		int i = 1;
		while(newConsole -> mid ->next != NULL){//mid ��尡 �������� while������ �̵��Ѵ�.
			if(newConsole -> mid -> data == searchInt){
				printf("�߰��Ͽ����ϴ�. %d���� ���", i);//i���� ��忡�� �߰�
			}
			newConsole -> mid = newConsole -> mid -> next;//����ĭ �̵�
			i++; //��� �� ����
		}
		if(newConsole -> tail -> data == searchInt){ //������ while������ �߰߾ȉ�
			printf("�߰��Ͽ����ϴ�. %d ��° ���", countNum);
		}
	}
}
void list_Clear(Node * ptr){
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr�� NULL�Դϴ�.");
		return ;
	}
	else
	{
		Node * tmpNode;//���� ���
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		tmpNode = ptr;
		while(ptr -> next != NULL)//���ʺ��� �ϳ��� �����Ѵ�.
		{
			ptr = ptr -> next;
			ptr -> prev = NULL;
			tmpNode ->next = NULL;
			tmpNode ->data = NULL;
			free(tmpNode);
			tmpNode = NULL;
			tmpNode = ptr;
		}
		if(ptr -> next == NULL)//������ ��带 ����
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
	Console* newConsole1;//���� �ܼ�
	newConsole1 = (Console *)malloc(sizeof(Console));
	Console* newConsole2;//������ ��� �ܼ�
	newConsole2 = (Console *)malloc(sizeof(Console));
	Node* newNode;//�ӽ� ��� �߰���
	
	if(ptr1 == NULL){
		printf("ptr1�� NULL�Դϴ�.");
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
		newNode = (Node *)malloc(sizeof(Node));//������ ����Ʈ�� ���
		newNode -> data = newConsole1 -> head -> data;
		newNode -> prev = NULL;
		newNode -> next = NULL;
		ptr2 = newNode;//����� ��� �߰�
		newConsole2 -> head = ptr2;
		newConsole2 -> mid = ptr2;
		while(newConsole1 -> mid -> next != NULL){
			newNode = NULL;
			newNode = (Node *)malloc(sizeof(Node));//�޸� �Ҵ�
			newNode -> data = newConsole1 -> mid -> data;//������ ����
			newNode -> prev = NULL;
			newNode -> next = NULL;
			while(newConsole2 ->mid -> next != NULL){
				newConsole2 -> mid = newConsole2 -> mid -> next;
			}//�ܼ�2 �̵带 ������
			newConsole2 -> mid -> next = newNode;//������ ���̱�
			newNode -> prev = newConsole2 -> mid;
			newConsole1 -> mid = newConsole1 -> mid -> next;//�ܼ�1 �̵� ��ĭ �ڷ�
		}
		if(newConsole1 -> mid -> next == NULL){//������ ���� ������
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
Node* list_Sort_Asc(Node * ptr)//�������ķ� �� ��������( ���� Ŀ��)
{
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	Node* tmpNode;//�ӽ� ���
	Node* saveNode = NULL;//��ġ ��� ���
	if(ptr == NULL){
		printf("ptr�� NULL");
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
		int countNum = list_cnt(newConsole -> mid); //�� ����
		newConsole -> mid = newConsole ->head; //�ٽ� ����ġ
		int position; // ù��ġ ����
		int tmp;//�����

		for(int i = 0 ; i < countNum ; i++){
			position = newConsole -> mid -> data; //������ ����
			tmpNode = newConsole -> mid;
			saveNode = newConsole -> mid;
			while(tmpNode-> next != NULL){
				tmp = tmpNode -> data;
				if(position > tmp){//tmp�� ���� �������� �ƶ�����
					position = tmp;
					saveNode = tmpNode;
				}
				tmpNode = tmpNode -> next;
			}
			if(tmpNode -> next == NULL){//������ üũ
				tmp = tmpNode -> data;
				if(position > tmp){//tmp�� ���� �������� �ƶ�����
					position = tmp;
					saveNode = tmpNode;
				}
			}
			saveNode -> data = newConsole -> mid -> data;//tmp����� �����͸� �����ǵ����͸� �������
			newConsole -> mid -> data = position;//�밥�� ����� �����Ϳ� ���� ���� tmp��
			newConsole -> mid = newConsole -> mid ->next;//head�� ��ĭ������
			tmpNode = NULL;//tmp���� �ʱ�ȭ
			saveNode = NULL;
		}
	}
	return ptr;
}
Node* list_Sort_Dec(Node * ptr){//�� ���ķ� �� ��������( ���� ������)
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	if(ptr == NULL){
		printf("ptr�� NULL");
	}
	else{
		while(ptr -> prev != NULL){ptr = ptr -> prev;}
		newConsole -> head = ptr;
		newConsole -> mid = ptr;
		while(ptr -> next != NULL){ptr = ptr -> next;}
		newConsole -> tail = ptr;
	}
	list_Sort_Dec_Quick(newConsole -> head, newConsole -> tail);//�Ӹ��� ���� �����ѵ� ������ ����
	return ptr;
}
void list_Sort_Dec_Quick(Node * head, Node * tail){//�� ����
	if(!head || !tail)//��峪 ������ �װų�
		return ;
	if(head == tail)//���� ������ �����ų�
		return ;
	Node * part = list_Sort_Dec_Partition(head, tail); //��Ƽ��
	Node * tmpNode1 = part -> prev , *tmpNode2 = part -> next;//������ �ٲٱ�
	if(head == part)
		tmpNode1 = part;
	if(part == tail)
		tmpNode2 = part;
	list_Sort_Dec_Quick(head, tmpNode1);
	list_Sort_Dec_Quick(tmpNode2, tail);
}
Node* list_Sort_Dec_Partition(Node* head, Node* tail){//�� ���� ��Ƽ��
	Node* start = head; //��ŸƮ ���
    int pivot = head->data; //�Ǻ�
    int flag = 0;//�� ���� ��

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
    //������ ����
    int temp = tail->data;
    tail->data = start->data;
    start->data = temp;
    return tail;
}
Node* list_Sort_Asc_Exchange(Node* ptr){//�������� ��ȯ����
	Console* newConsole;
	newConsole = (Console *)malloc(sizeof(Console));
	Node* tmpNode;//�ӽ� ���
	if(ptr == NULL){
		printf("ptr�� NULL");
	}
	else{
		while(ptr -> prev != NULL){
			ptr = ptr -> prev;
		}
		newConsole -> head = ptr;//���
		newConsole -> mid = ptr;//�̵�
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		newConsole -> tail = ptr;//����
		int countNum = list_cnt(newConsole -> mid); //�� ����
		newConsole -> mid = newConsole ->head; //�ٽ� ����ġ
		int tmp;//�����
		for(int i = 0 ; i < countNum ; i++){
			tmpNode = newConsole -> mid -> next;
			while(tmpNode-> next != NULL){
				tmp = tmpNode -> data;
				if(newConsole -> mid -> data > tmp){//tmp�� ���� �������� �ƶ�����
					tmpNode -> data = newConsole ->mid -> data;//��� ������ ��ȯ
					newConsole -> mid -> data = tmp;//��� ������ ��ȯ2
				}
				tmpNode = tmpNode -> next;
			}
			if(tmpNode -> next == NULL){//������ üũ
				tmp = tmpNode -> data;
				if(newConsole -> mid -> data > tmp){//tmp�� ���� �������� �ƶ�����
					tmpNode -> data = newConsole ->mid -> data;
					newConsole -> mid -> data = tmp;
				}
				newConsole -> mid = newConsole -> mid ->next;//head�� ��ĭ������
				tmpNode = NULL;//tmp���� �ʱ�ȭ
			}
		}
		newConsole = NULL;
		free(newConsole);
		tmpNode = NULL;
		free(tmpNode);
	return ptr;
	}
}
void list_print(Node * ptr){//����� ���� ���¸� Ȯ���ϴ� �Լ�
	Node* tmpNode;
	if(ptr == NULL){
		printf("ptr�� NULL");
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
		printf("ptr�� NULL");
	}
	else{
		while(ptr -> prev != NULL){ptr = ptr -> prev;}
		newConsole -> head = ptr;
		newConsole -> mid = ptr;
		while(ptr -> next != NULL){ptr = ptr -> next;}
		newConsole -> tail = ptr;
	}
	int arraySize =  list_cnt(ptr);//������
	tmpArray * myArray;//�÷��ú� �ӽ� �迭
	int mallocSize = sizeof(tmpArray) + sizeof(int)*(arraySize+1);
	myArray = (tmpArray *)malloc(mallocSize);//ũ�� �Ҵ�
	for(int i = 0; i < arraySize ; i ++){
		myArray -> List[i] = newConsole -> mid -> data; //������ ����
		newConsole -> mid = newConsole -> mid ->next;
	}
	newConsole -> mid = newConsole -> head;
	array_mergeSort(myArray -> List , 0, arraySize);//�ո� ���� ����
	for(int j = 0; j < arraySize ; j ++){
		newConsole -> mid -> data = myArray -> List[j];//������ �������,
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
	tmpArray * myArray2;//�÷��ú� �ӽ� �迭
	int x = n1 + n2;
	myArray2 = (tmpArray *)malloc(sizeof(tmpArray) + sizeof(int)*x);//ũ�� �Ҵ�
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