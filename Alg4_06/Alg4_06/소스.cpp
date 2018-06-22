#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void floyd2(int n, const int W[][7], int D[][7], int P[][7]);
void path(int q, int r);
void path2(int q, int r);
int P[7][7] = {};
int P_reverse[7][7] = {};
int main(){
	const int originW[7][7] = {{0,4,0,0,0,10,0},{3,0,0,18,0,0,0},{0,6,0,0,0,0,0},{0,5,15,0,2,19,5},{0,0,12,1,0,0,0},{0,0,0,0,0,0,10},{0,0,0,8,0,0,0}};//���� 5�� �׷��� ����ġ
	int D[7][7] = {};
	floyd2(7,originW,D,P);
	printf("\n");
	path(6,2);//V7 -> V3 ���� ���İ��� vertex ����Ʈ
	printf("\n");
	path2(6,2);
	return 0;
}
void floyd2(int n, const int W[][7], int D[][7], int P[][7]){
	int i=0,j=0,k=0;

	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
			D[i][j] = 0;//�ʱ�ȭ
	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
			P[i][j] = 0;//�ʱ�ȭ
	printf("D[7][7]�� �׷���\n");

	for(i = 0; i < n ; i++)
		for(j=0; j<n; j++)
		{
			if(W[i][j] == 0)
				D[i][j] = 99;//99�� ��ǻ� ���Ѵ�
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
						D[i][j] = D[i][k] + D[k][j];//����ġ ����
					}
				}
			}
		}	
		printf("\n");
		printf("P[7][7]�� �׷���\n");
		for(i = 0; i < n ; i++){
			for(j=0; j<n; j++)
			{
			printf("%4d", P[i][j]);
			if(j == 6)
				printf("\n");
			}
		}
		printf("D[7][7]�� �׷���\n");
		for(i = 0; i < n ; i++){
			for(j=0; j<n; j++)
			{
			printf("%4d", D[i][j]); 
			if(j == 6)
				printf("\n");
			}
		}
		printf("V7 -> V3 : %d", D[6][2]); //6�� ����
		//----------------����� �߰�
		for(i = 0; i < n ; i++)
		{
			for(j = 0 ; j < n ; j++)
			{
				P_reverse[i][j] = P[j][i];
			}
		}
		printf("\n");
		for(i = 0; i < n ; i++){
			for(j=0; j<n; j++)
			{
			printf("%4d", P_reverse[i][j]);
			if(j == 6)
				printf("\n");
			}
		}
}
void path(int q, int r){
	if(P[q][r] != 0){
		path(q, P[q][r]-1);// -1 �� �ϴ� ������ floyd2�Լ����� k�� 1�� ���� ���·� �����ؼ� �ٽ� ������ �����÷ο찡 �߻����� �ʴ´�.
		cout<<"v"<<P[q][r];
		path(P[q][r]-1,r);
	}
}
void path2(int q, int r){
	if(P_reverse[q][r] != 0){
		path(q, P_reverse[q][r]-1);// -1 �� �ϴ� ������ floyd2�Լ����� k�� 1�� ���� ���·� �����ؼ� �ٽ� ������ �����÷ο찡 �߻����� �ʴ´�.
		cout<<"v"<<P_reverse[q][r];
		path(P_reverse[q][r]-1,r);
	}
}