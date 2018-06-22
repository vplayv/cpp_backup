#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAX_WEIGHT 9

/*	0-1 Knapsack Problem D-F-S
	순서대로 index : (Profit, Weight)
				1 : (20,2)
				2 : (30,5)
				3 : (35,7)
				4 : (12,3)
				5 : (3,1)
	Problem : n(5)개의 아이템을 준다
			  이 5개의 아이템은 각각 무게와 이익을 포함한다.
			  W(제한무게)를 준다. 이익을 극대화 시키며, 제한 무게 W를 넘지 않는 정답을 구하라.
	Input	: n , W, w[1...n], p[1..n]이다. w,p배열은 반드시 양수이다.
			  p/w가 가장 높은 순으로 순서 index를 정한다.
	output	: boolean 형의 bestest[1..n]이다. 0이면 미포함, 1이면 포함이다.

	변수 : maxProfit, Profit, Weight, bound, totalWeight이다.
	maxProfit : 지금까지 찾은 최선의 해답이 주는 값어치.
	bound	  : 모르겠다. 아마도 앞으로 얻을 수있는 효율인듯하다.
	if bound <= maxProfit, then : 노드 레벨 i는 유망하지 않다.
	maxprofit = 0 으로 초기화 (전역)
	profit = 0으로 초기화
	weight = 0으로 초기화
	
*/
int maxProfit = 0;//지금 까지 찾은 최선의 해답이 주는 값어치 
bool bestset[N+1] = {false,false,false,false,false,false};//정답.
bool include[N+1] = {false,false,false,false,false,false};//포함여부
int numset[N+1] = {0};//뭐지
int w[N+1] = {0,2,5,7,3,1};
int p[N+1] = {0,20,30,35,12,3};
void knapsack(int, int, int);
bool promising(int);
bool promising(int i){
	int j, k;
	int totalWeight;
	float bound;
	int weight = 0, profit = 0;
	for(int tmp = 1; tmp <= i; tmp ++){
		if(include[tmp] == true){
			weight = weight + w[tmp];
			profit = profit + p[tmp];
		}
	}
	printf(" Promising? Profit : %d, Weight : %d\n",profit,weight);
	if(weight >= MAX_WEIGHT)
		return false;
	else
	{
		j = i+1;
		bound = (float)profit;
		totalWeight = weight;
		while((j <= N) && (totalWeight + w[j] <= MAX_WEIGHT))
		{
			totalWeight = totalWeight + w[j];
			bound = bound + (float)p[j];
			j++;
		}
		k = j;
		if(k <= N)
			bound = bound + (float)((MAX_WEIGHT - totalWeight) * (p[k]/w[k]));
		printf(" Bound : %f\n", bound);
		return (bound>(float)maxProfit);
		
	}
}
void knapsack(int i, int profit, int weight){
	printf(" LEVEL : %d , Profit : %d, Weight : %d \n",i,profit,weight);
	if(weight <= MAX_WEIGHT && profit > maxProfit)
	{
		maxProfit = profit;
		numset[i] = i;
		for(int tmp = 1; tmp <= N; tmp ++)
			bestset[tmp] = include[tmp];
	}

	if(promising(i))
	{
		include[i+1] = true;
		knapsack(i+1, profit + p[i+1], weight + w[i+1]);
		include[i+1] = false;
		knapsack(i+1, profit,weight);
	}
}
int main(){
	knapsack(0,0,0);//시작
	for(int tmp = 1 ; tmp <= N ; tmp++)
		printf("%d번째 : %d\n",tmp,bestset[tmp]);
	printf("MAX : %d \n",maxProfit);
	//for(int tmp = 1 ; tmp <= N ; tmp++)
	//	printf("%d번째 : %d\n",tmp,numset[tmp]);
	return 0;
}