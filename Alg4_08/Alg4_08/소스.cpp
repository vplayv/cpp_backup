#include <stdio.h>
#include <stdlib.h>
void floyd2(int n, const int W[][7], int D[][7], int P[][7]);
int main(){
	const int originW[7][7] = {{0,4,0,0,0,10,0},{3,0,0,18,0,0,0},{0,6,0,0,0,0,0},{0,5,15,0,2,19,5},{0,0,12,1,0,0,0},{0,0,0,0,0,0,10},{0,0,0,8,0,0,0}};//문제 5번 그래프 가중치
	int D[7][7] = {};
	int P[7][7] = {};
	floyd2(7,originW,D,P);
	const int originW2[7][7] = {{0,4,0,0,0,10,9},{3,0,0,18,0,0,0},{0,6,0,0,0,0,14},{0,5,15,0,2,19,5},{0,0,12,1,0,0,0},{9,0,0,0,0,0,10},{0,13,0,8,0,0,0}};//새로운 그래프
	floyd2(7,originW2,D,P);
	return 0;
}
void floyd2(int n, const int W[][7], int D[][7], int P[][7]){
	int i=0,j=0,k=0;

	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
			D[i][j] = 0;//초기화
	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
			P[i][j] = 0;//초기화
	printf("\nD[7][7]의 그래프\n");

	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
		{
			if(W[i][j] == 0)
				D[i][j] = 99;//99는 사실상 무한대
			else
				D[i][j] = W[i][j];//D = W
			printf("%4d", D[i][j]);
			if(j == 6)
				printf("\n");
		}
		for(k = 0; k < n ; k++){
			for(i = 0; i < n ; i++){
				for(j = 0; j < n ; j++){
					if(D[i][k] + D[k][j] < D[i][j]){
						//printf("D[%d][%d](%d) + D[%d][%d](%d) < D[%d][%d](%d)\n", i,k,D[i][k],k,j,D[k][j],i,j,D[i][j]);
						//printf("P[%d][%d] = %d\n", i,j, k);
						P[i][j] = k+1 ;
						printf("D[%d][%d](%d) = D[%d][%d](%d) + D[%d][%d](%d)\n" , i,j,D[i][j],i,k,D[i][k],k,j,D[k][j]);
						D[i][j] = D[i][k] + D[k][j];//가중치 갱신
					}
				}
			}
		}	
		printf("\n");
		printf("P[7][7]의 그래프\n");
		for(i = 0; i < n ; i++){
			for(j=0; j<n; j++)
			{
			printf("%4d", P[i][j]);
			if(j == 6)
				printf("\n");
			}
		}
		printf("D[7][7]의 그래프\n");
		for(i = 0; i < n ; i++){
			for(j=0; j<n; j++)
			{
			printf("%4d", D[i][j]); 
			if(j == 6)
				printf("\n");
			}
		}
		printf("V7 -> V3 : %d", D[6][2]); //6번 정답
}