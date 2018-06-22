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
}; // ��� FALSE �����γ� ���� ����ִ� �𼭸� ����
int output[10][2] = {0};
void prim(int n){//n = 10
	//F�� �𼭸��� ����
	int i, vnear;	//INDEX
	int min;		//MIN
	int edge;		//Edge e
	int nearest[myN];	//[2..n]
	int distance[myN];	//[2..n]
	//F = ������ 1.2����, bool ����
	printf("�ʱ�ȭ\n");
	for(i = 1; i < n ; i++){ 
		nearest[i] = 0;			//V1���� ���� ����� ������ v1���� �ʱ�ȭ
		distance[i] = W[0][i];	//vi�� v1�� �մ� �������� ����ġ���ʱ�ȭ
		printf("nearest[%d] : %d, distance[%d] = %d\n",i, nearest[i], i, distance[i]);
	}

	for(int j = 1; j < 10 ; j++)//n-1���� ������ Y�� �߰��Ѵ�.
	{
		min = myMax;
		//=======================================
		for(i = 1; i < n ; i++){//�� ������ ���ؼ� distance[i]�� �˻��Ͽ� ���� ����� vnear�� ã�´�.
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
		distance[vnear] = -1;//ã�� ��带 Y�� �߰��Ѵ�.
		for(i=1;i<n;i++){
			if(W[i][vnear] < distance[i]){
				distance[i] = W[i][vnear];	//Y�� ���� �� ��忡 ���ؼ�
				nearest[i] = vnear;			//distance[i]�� �����Ѵ�.
				printf("\n nearest[%d] = %d distance[%d] = %d", i, nearest[i], i,  W[i][vnear]);
			}
		}
	}
	printf("���� ������� ���\n");
	for(i = 0; i < myN -1  ; i++){	
		printf(" ���� ����%d ��° : V%d - V%d \n", i+1 ,output[i][1]+1, output[i][0]+1);
	}
}

int main(){
	prim(myN);
	return 0;
}