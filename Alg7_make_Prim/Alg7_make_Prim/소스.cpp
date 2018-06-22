#include <stdio.h>
#include <stdlib.h>
#define myN 10
#define myMax 1000
const int W[myN][myN] ={
	{0,32,myMax,17,myMax,myMax,myMax,myMax,myMax,myMax},
	{32,0,myMax,myMax,45,myMax,myMax,myMax,myMax,myMax},
	{myMax,myMax,0,18,myMax,myMax,5,myMax,myMax,myMax},
	{17,myMax,18,0,10,myMax,myMax,3,myMax,myMax},
	{myMax,45,myMax,10,0,28,myMax,myMax,25,myMax},
	{myMax,myMax,myMax,myMax,28,0,myMax,myMax,myMax,6},
	{myMax,myMax,5,myMax,myMax,myMax,0,59,myMax,myMax},
	{myMax,myMax,myMax,3,myMax,myMax,59,0,4,myMax},
	{myMax,myMax,myMax,myMax,25,myMax,myMax,4,0,12},
	{myMax,myMax,myMax,myMax,myMax,6,myMax,myMax,12,0},
};
bool F[myN][myN] = {
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
}; // 모두 FALSE 상태인놈 현재 비어있는 모서리 집합
int output[10][2] = {0};
void prim(int n){//n = 10
	//F는 모서리의 집합
	int i, vnear;	//INDEX
	int min;		//MIN
	int edge;		//Edge e
	int nearest[myN];	//[2..n]
	int distance[myN];	//[2..n]
	//F = 공집합 1.2진접, bool 집함
	printf("초기화\n");
	for(i = 1; i < n ; i++){ 
		nearest[i] = 0;			//V1에서 가장 가까운 정점을 v1으로 초기화
		distance[i] = W[0][i];	//vi과 v1을 잇는 이음선의 가중치로초기화
		printf("nearest[%d] : %d, distance[%d] = %d\n",i, nearest[i], i, distance[i]);
	}

	for(int j = 1; j < 10 ; j++)//n-1개의 정점을 Y에 추가한다.
	{
		min = myMax;
		//=======================================
		for(i = 1; i < n ; i++){//각 정점에 대해서 distance[i]를 검사하여 가장 가까운 vnear를 찾는다.
			if(0 <= distance[i] && distance[i] <= min){
				min = distance[i];
				vnear = i;
				printf("\n min = %d vnear = %d", distance[i], i);
			}
		}
		//=======================================
		//e = edge connecting vertices indexed by vnear and nearest[vnear]
		//add e to F
		printf("\n vnear : %d, nearest[vnear] : %d \n", vnear, nearest[vnear]);
		F[vnear][nearest[vnear]] = true;
		output[j-1][0] = vnear;
		output[j-1][1] = nearest[vnear];
		distance[vnear] = -1;//찾은 노드를 Y에 추가한다.
		for(i=1;i<n;i++){
			if(W[i][vnear] < distance[i]){
				distance[i] = W[i][vnear];	//Y에 없는 각 노드에 대해서
				nearest[i] = vnear;			//distance[i]를 갱신한다.
				printf("\n nearest[%d] = %d distance[%d] = %d", i, nearest[i], i,  W[i][vnear]);
			}
		}
	}
	printf("정답 순서대로 출력\n");
	for(i = 0; i < myN -1  ; i++){	
		printf(" 연결 순서%d 번째 : V%d - V%d \n", i+1 ,output[i][1]+1, output[i][0]+1);
	}
}

int main(){
	prim(myN);
	return 0;
}