/*
	���� ���İ� �������� �����.
	���� ��ũ�� ����Ʈ�� �����. ���� Int�� ���� ���� ���� �����.
	�����ڴ� Tail, Head, Mid�� �����Ѵ�. �������� ���İ� �������� ���� �߰��Ѵ�.
	�������� ȯ���̹Ƿ� QueryPerformanceCounter, QueryPerformanceFrequency�� ����Ѵ�.
	������� �Ѵ�. �ּ��� �ܴ�. ����?�� �Ѵ�. �˰��� ���� ��
*/
#include <iostream>
#include <ctime>
using namespace std;

class Node;				//��� Ŭ���� ����
class DoubleList;		//����ũ�帮��Ʈ Ŭ���� ����

class Node{//Ŭ���� ���
	friend class DoubleList;
private:
	int Data;
	Node * BeforeNode;
	Node * NextNode;
public:
	Node(){
		Data = 0;
		BeforeNode = NULL;
		NextNode = NULL;
	}
	Node(int Input){
		Data = Input;
		BeforeNode = NULL;
		NextNode = NULL;
	}
	~Node(){}
};
class DoubleList{//Ŭ���� ����ũ�帮��Ʈ
private:
	Node * Head;
	Node * Tail;
	int cnt;

public:
	DoubleList()
	:cnt(0)
	{
		Head = NULL;
		Tail = NULL;
	}
	void List_Insert_Head(Node * insertNode){
	if(Head == NULL){
		//Head =
	}
	};
	void List_Insert_Tail();
	void List_Insert_index();
	
};