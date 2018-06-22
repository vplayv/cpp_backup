#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#define myN 5//점은 5개니깐
#define myMAX 1000//사실상 무한대
/*
	1. 5개의 Edge를 기준으로함 시작은 언제나 v1
	2. 28번의 가중치 W를 이용함
	3. index P[][]는 전역으로 한다.
	4. D[1..n][subset of V - {v1}]
	5. 29번의 디테일 버전까지 같이한다.
	6. 실제 정답은 Length = 29, 경로는 123541 이다.
	7. V = set of Vertices
	8. A = a subset of V
	9. 공집합 표시는 A가 없을때
	10. D[vi][A] = vi에서 v1으로 가는 최단 경로. 반드시 A의 하나는 지나야 한다.
*/
using namespace std;
const int W[myN+1][myN+1] = {
	{0,0,0,0,0,0},
	{0,0,8,13,18,20},
	{0,3,0,7,8,10},
	{0,4,11,0,10,7},
	{0,6,6,7,0,11},
	{0,10,6,2,1,0}
};//28번의 가중치는 const로 묶어논다.[0]번 라인은 쓰레기임
int D[myN+1][myN+1];
int P[myN+1][myN+1] = {0};
void travel(int n, int& minLength);//함수선언

int main(){
	return 0;
}
void travel(int n, int& minLength){
	int i = 0, j = 0, k = 0;//인덱스들
	int tmpJ = 0, tmp1 = myMAX, tmp2 = myMAX, tmp3 = myMAX;//임시저장용
	int tmpV1 = 0; int tmpV2 = 0, tmpV3 = 0, tmpV4 = 0;
	for(i = 0; i <= myMAX; i++){
		for(j = 0; j <= myMAX; j++){
			D[i][j] = myMAX;//쓰레기값까지 포함하여 모두 1000으로 초기화시킴
		}
	}
	for(i=2; i<= n ; i++){
		D[i][1] = W[i][1];//3,4,6,10이 들어가야함
	}
	for(k=1; k<= n-2; k++){//k=1일때 4번, k=2일때 6번, k=3일때 4번
		for(int x = 2 ; x <= n-k+1 ; x++){//all subset A=V-v1 containing K vertices
			/*
			k = 1일때 v2,v3,v4,v5
			k = 2일때 (v2,v3),(v2,v4),(v2v5)(v3v4)(35)(45)
			k = 3일때 (234)(235)(245)(345)
			*/
			for(i = x; i <= n; i ++ ){//i such that i != 1 and vi is not in A
				//임시변수들 초기화
				tmp1 = myMAX, tmp2 = myMAX, tmp3 = myMAX;
				if(i == x){
					//아무것도 안함..
				}
				else{
					while(false){

					}
					D[i][x] = tmp3;
					P[i][x];
				}
			}
		}
	}
}