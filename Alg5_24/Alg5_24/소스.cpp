#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define myN 10
#define infi 9999
/*
	1. 노드는 10개를 기준으로 만듬. 즉 n = 10
*/
using namespace std;
struct myNode{
	int key;
	myNode* left;
	myNode* right;
};//노드 구조체

//========함수 목록==========================
void search(myNode* tree, float keyin, myNode*& p);//서치 함수
void opt(int n, float& minavg);//옵티멀 함수
myNode* tree(int i , int j, int depth);//트리 만드는 함수

//========미리 지정된 배열 목록==============
float myGameArray[myN+1] = {0, 0.07, 0.11, 0.15, 0.14, 0.22, 0.13, 0.03, 0.06, 0.08, 0.01};//미리 설정된 확률
int myKeyArray[myN+1] = {0,17,33,19,42,8,11,74,69,55,24};//키값
float A[myN+1 + 1][myN + 1] = {0};//미리 지정된 12*11 행렬 A (1~n+1,0~n)
int R[myN+1 + 1][myN + 1] = {0};//미리 지정된 12*11 행렬 P (1~n+1,0~n)
int main(){
	float resultAVG = 0;//AVG값
	opt(10, resultAVG);
	myNode* myTree = NULL;
	myTree = tree(1,10, 1);
	return 0;
}
void opt(int n, float& minavg){//n은 무조건 10
	int i = 0, j = 0, k = 0, diagonal = 0;
	float tmp1 = 0, tmp2 = 0, tmp3 = infi, tmpK = 0, tmpSum = 0;//임시 K저장용
	for(i = 1; i <= n; i++){//초기화
		A[i][i-1] = 0;
		A[i][i] = myGameArray[i];
		R[i][i] = i;
		R[i][i-1] = 0;
	}
	A[n+1][n] = 0;//초기화
	R[n+1][n] = 0;
	for(diagonal =1 ; diagonal <= n-1; diagonal++){
		for(i = 1 ; i <= n-diagonal; i++){
			j = i + diagonal;//j입력
			k = i;//k 입력
			tmpSum = 0;
			tmp1 = 0; tmp2 = 0; tmp3 = 0;
			for(int m = i; m <= j ; m++){
				tmpSum = tmpSum + myGameArray[m];
			}//확률 계산
			printf("tmpsum = %.2f ",tmpSum);
			tmp1 = A[i][k-1] + A[k+1][j];//while문 못들어갈때
			tmp3 = tmp1;//while문에 못들어갈때
			tmpK = k;//while문에 못들어갈때;
			while(k+1 <= j){
				tmp1 = A[i][k-1] + A[k+1][j];//임시 1
				tmp2 = A[i][k] + A[k+2][j];//임시2
				if(tmp1 < tmp2 && tmp1 < tmp3){//비교
					tmp3 = tmp1;
					tmpK = k;
				}
				else if(tmp2 < tmp1 && tmp2 < tmp3){
					tmp3 = tmp2;
					tmpK = k+1;
				}
				k++;
			}
			printf(" tmp3 : %.2f\n", tmp3);
			A[i][j] = tmp3 + tmpSum;//A = min()+sigmaP
			R[i][j] = tmpK;//최소의 숫자일때의 K
		}
	}
	minavg = A[1][n];
	printf("MINAVG = %.2f\n", minavg);
	printf("A[][]출력\n");
	printf("      %6d%5d%5d%6d%6d%6d%6d%6d%6d%6d%6d\n",0,1,2,3,4,5,6,7,8,9,10);
	for(i = 1; i <myN + 2; i++){
		printf("%6d ",i);
		for(j = 0; j < myN + 1; j++){
			printf(" %5.2f", A[i][j]);
			if(j == myN)
				printf("\n");
		}
	}
	printf("R[][]출력\n");
	printf("      %4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",0,1,2,3,4,5,6,7,8,9,10);
	for(i = 1; i <myN + 2; i++){
		printf("%6d ",i);
		for(j = 0; j < myN + 1; j++){
			printf("%4d", R[i][j]);
			if(j == myN)
				printf("\n");
		}
	}
}
void search(myNode* tree, int keyin, myNode*& p){//찾는 함수
	bool found = false;
	p = tree;
	while(!found){
		if(p->key == keyin)
			found = true;
		else if(keyin < p->key)
			p = p -> left;
		else
			p = p -> right;
	}
}
myNode* tree(int i, int j, int depth){
	int k;
	myNode* p;
	int thislevel = depth;//차이 구분
	k = R[i][j];//노드를 만들기위함
	if(k == 0)
		return 0;
	else{
		p = (myNode*)malloc(sizeof(myNode)+4);//노드 형성
		p -> key = myKeyArray[k];
		for(int u = 1; u <= thislevel; u++){
			printf("   ");
		}
		printf("%d\n", myKeyArray[k]);
		++thislevel;//깊이 증가
		p -> left = tree(i, k-1, thislevel);//왼쪽 부터
		p -> right = tree(k+1, j, thislevel);//오른쪽
		return p;
	}
}