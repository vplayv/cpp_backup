#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAX_WEIGHT 9
using namespace std;
struct node;
/*	0-1 Knapsack Problem Best..Branch and bound(가지치기, 분기 한정법)
	Node 구조체를 사용한다.
	큐를 사용한다.
	Node {level,profit,weight}

	Problem : n(5)개의 아이템을 준다
			  이 5개의 아이템은 각각 무게와 이익을 포함한다.
			  W(제한무게)를 준다. 이익을 극대화 시키며, 제한 무게 W를 넘지 않는 정답을 구하라.
	Input	: n , W, w[1...n], p[1..n]이다. w,p배열은 반드시 양수이다.
			  p/w가 가장 높은 순으로 순서 index를 정한다.
	output	: MAX Profit이다.

	변수 : maxProfit, Profit, Weight, bound, totalWeight이다.
	maxProfit : 지금까지 찾은 최선의 해답이 주는 값어치.
	bound	  : 앞으로 얻을 수있는 효율인듯하다.
	if bound <= maxProfit, then : 노드 레벨 i는 유망하지 않다.
	maxprofit = 0 으로 초기화 (전역)
	profit = 0으로 초기화
	weight = 0으로 초기화
	
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
		while(Q.last -> next != NULL){//last의 다음이 NULL일때까지
			Q.last = Q.last -> next;//last를 맨뒤로 옮긴다.
		}
		Q.last -> next = n;//last 뒤쪽에 추가된 n을 붙인다.
		Q.last = Q.last -> next;//그리고 last를 다시 맨뒤로 옮김.
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
	printf("정답 : %d",answer);
	return 0;
}