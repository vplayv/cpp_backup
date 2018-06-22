#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAX_WEIGHT 9

/*	0-1 Knapsack Problem D-F-S
	������� index : (Profit, Weight)
				1 : (20,2)
				2 : (30,5)
				3 : (35,7)
				4 : (12,3)
				5 : (3,1)
	Problem : n(5)���� �������� �ش�
			  �� 5���� �������� ���� ���Կ� ������ �����Ѵ�.
			  W(���ѹ���)�� �ش�. ������ �ش�ȭ ��Ű��, ���� ���� W�� ���� �ʴ� ������ ���϶�.
	Input	: n , W, w[1...n], p[1..n]�̴�. w,p�迭�� �ݵ�� ����̴�.
			  p/w�� ���� ���� ������ ���� index�� ���Ѵ�.
	output	: boolean ���� bestest[1..n]�̴�. 0�̸� ������, 1�̸� �����̴�.

	���� : maxProfit, Profit, Weight, bound, totalWeight�̴�.
	maxProfit : ���ݱ��� ã�� �ּ��� �ش��� �ִ� ����ġ.
	bound	  : �𸣰ڴ�. �Ƹ��� ������ ���� ���ִ� ȿ���ε��ϴ�.
	if bound <= maxProfit, then : ��� ���� i�� �������� �ʴ�.
	maxprofit = 0 ���� �ʱ�ȭ (����)
	profit = 0���� �ʱ�ȭ
	weight = 0���� �ʱ�ȭ
	
*/
int maxProfit = 0;//���� ���� ã�� �ּ��� �ش��� �ִ� ����ġ 
bool bestset[N+1] = {false,false,false,false,false,false};//����.
bool include[N+1] = {false,false,false,false,false,false};//���Կ���
int numset[N+1] = {0};//����
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
	knapsack(0,0,0);//����
	for(int tmp = 1 ; tmp <= N ; tmp++)
		printf("%d��° : %d\n",tmp,bestset[tmp]);
	printf("MAX : %d \n",maxProfit);
	//for(int tmp = 1 ; tmp <= N ; tmp++)
	//	printf("%d��° : %d\n",tmp,numset[tmp]);
	return 0;
}