#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAX_WEIGHT 9
using namespace std;
struct node;
/*	0-1 Knapsack Problem Best..Branch and bound(����ġ��, �б� ������)
	Node ����ü�� ����Ѵ�.
	ť�� ����Ѵ�.
	Node {level,profit,weight}

	Problem : n(5)���� �������� �ش�
			  �� 5���� �������� ���� ���Կ� ������ �����Ѵ�.
			  W(���ѹ���)�� �ش�. ������ �ش�ȭ ��Ű��, ���� ���� W�� ���� �ʴ� ������ ���϶�.
	Input	: n , W, w[1...n], p[1..n]�̴�. w,p�迭�� �ݵ�� ����̴�.
			  p/w�� ���� ���� ������ ���� index�� ���Ѵ�.
	output	: MAX Profit�̴�.

	���� : maxProfit, Profit, Weight, bound, totalWeight�̴�.
	maxProfit : ���ݱ��� ã�� �ּ��� �ش��� �ִ� ����ġ.
	bound	  : ������ ���� ���ִ� ȿ���ε��ϴ�.
	if bound <= maxProfit, then : ��� ���� i�� �������� �ʴ�.
	maxprofit = 0 ���� �ʱ�ȭ (����)
	profit = 0���� �ʱ�ȭ
	weight = 0���� �ʱ�ȭ
	
*/
struct node{
	node* next;
	int level;
	int profit;
	int weight;
	float bound;
};
struct queue_of_node{
	node* first;
	node* last;
};
const int w[N+1] = {0,2,5,7,3,1};
const int p[N+1] = {0,20,30,35,12,3};

void knapsack(int n, int maxW, int &maxprofit);
float bound(node u);
void insert(queue_of_node &Q, node);
void remove(queue_of_node &Q, node &);
bool empty(queue_of_node &Q);
void initialize(queue_of_node &Q);
bool empty(queue_of_node &Q){
	if(Q.first == NULL)
		return true;
	else
		return false;
}
void initialize(queue_of_node &Q){
	Q.first = (node*)malloc(sizeof(node*));
	Q.last = (node*)malloc(sizeof(node*));
	Q.first  = NULL;
	Q.last   = NULL;
}

void insert(queue_of_node &Q, node inputNode){
	node* n = (node*)malloc(sizeof(node*));
	n ->level = inputNode.level;
	n ->profit = inputNode.profit;
	n ->weight = inputNode.weight;
	n ->next = NULL;
	if(Q.first == NULL && Q.last == NULL){
		Q.first = n;
		Q.last = n;
	}
	else{
		while(Q.last -> next != NULL){//last�� ������ NULL�϶�����
			Q.last = Q.last -> next;//last�� �ǵڷ� �ű��.
		}
		Q.last -> next = n;//last ���ʿ� �߰��� n�� ���δ�.
		Q.last = Q.last -> next;//�׸��� last�� �ٽ� �ǵڷ� �ű�.
	}
}
void remove(queue_of_node &Q, node &v){
	node* n = (node*)malloc(sizeof(node*));
	if(Q.first == NULL && Q.last == NULL){
		return ;
	}
	else{
		if(Q.first == Q.last)
		{
			v.level = Q.first ->level;
			v.profit = Q.first -> profit;
			v.weight = Q.first -> weight;
			Q.last = NULL;
			//free(Q.first);
			Q.first = NULL;
		}
		else{
			v.level = Q.first ->level;
			v.profit = Q.first -> profit;
			v.weight = Q.first -> weight;
			n = Q.first;
			Q.first = Q.first -> next;
			n -> next = NULL;
			//free(n);
		}
	}
}
void knapsack(int n, int maxW, int &maxprofit){
	queue_of_node Q;
	node u, v;
	initialize(Q);
	v.level = 0; v.profit = 0; v.weight = 0; maxprofit = 0; v.bound = bound(v);
	insert(Q,v);
	while(!empty(Q)){
			remove(Q,v);
			if(v.bound > maxprofit){
					u.level = v.level + 1;
			u.profit= v.profit + p[u.level];
			u.weight= v.weight + w[u.level];
			printf("u.p = %d, u.w = %d\n",u.profit, u.weight);
			if((u.weight <= MAX_WEIGHT) && (u.profit > maxprofit))
				maxprofit = u.profit;
			if(bound(u) > maxprofit)
				insert(Q,u);
			else
				printf("CUT LEVEL : %d\n",u.level);
			u.weight = v.weight;
			u.profit = v.profit;
			u.bound = bound(u);
			if(bound(u) > maxprofit)
				insert(Q,u);
			else
				printf("CUT LEVEL : %d\n",u.level);
			}
	}

}
float bound(node u){
	int j,k;
	int totalWeight;
	float result;
	if(u.weight >= MAX_WEIGHT)
		return 0;
	else
	{
		result = u.profit;
		j = u.level + 1;
		totalWeight = u.weight;
		while((j<=N) && (totalWeight + w[j] <= MAX_WEIGHT)){
			totalWeight = totalWeight + w[j];
			result = result + p[j];
			j++;
		}
		k = j;
		if(k <= N)
			result = result + (MAX_WEIGHT - totalWeight) * (p[k]/w[k]);
		printf("bound(result) : %.1f\n", result);
		return result;
	}
}
int main(){
	int answer = 0;
	knapsack(N,MAX_WEIGHT,answer);
	printf("���� : %d",answer);
	return 0;
}