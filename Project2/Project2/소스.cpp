/*
	선택 정렬과 퀵정렬을 만든다.
	이중 링크드 리스트를 만든다. 노드는 Int형 이중 방향 노드로 만든다.
	관리자는 Tail, Head, Mid로 관리한다. 오름차순 정렬과 내림차순 정렬 추가한다.
	윈도우즈 환경이므로 QueryPerformanceCounter, QueryPerformanceFrequency를 사용한다.
	디버깅을 한다. 주석을 단다. 고찰?을 한다. 알고리즘 성능 비교
*/
#include <iostream>
#include <ctime>
using namespace std;

class Node;				//노드 클래스 선언
class DoubleList;		//더블링크드리스트 클래스 선언

class Node{//클래스 노드
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
class DoubleList{//클래스 더블링크드리스트
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