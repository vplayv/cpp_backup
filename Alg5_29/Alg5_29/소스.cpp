#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#define myN 5//���� 5���ϱ�
#define myMAX 1000//��ǻ� ���Ѵ�
/*
	1. 5���� Edge�� ���������� ������ ������ v1
	2. 28���� ����ġ W�� �̿���
	3. index P[][]�� �������� �Ѵ�.
	4. D[1..n][subset of V - {v1}]
	5. 29���� ������ �������� �����Ѵ�.
	6. ���� ������ Length = 29, ��δ� 123541 �̴�.
	7. V = set of Vertices
	8. A = a subset of V
	9. ������ ǥ�ô� A�� ������
	10. D[vi][A] = vi���� v1���� ���� �ִ� ���. �ݵ�� A�� �ϳ��� ������ �Ѵ�.
*/
using namespace std;
const int W[myN+1][myN+1] = {
	{0,0,0,0,0,0},
	{0,0,8,13,18,20},
	{0,3,0,7,8,10},
	{0,4,11,0,10,7},
	{0,6,6,7,0,11},
	{0,10,6,2,1,0}
};//28���� ����ġ�� const�� ������.[0]�� ������ ��������
int D[myN+1][myN+1];
int P[myN+1][myN+1] = {0};
void travel(int n, int& minLength);//�Լ�����

int main(){
	return 0;
}
void travel(int n, int& minLength){
	int i = 0, j = 0, k = 0;//�ε�����
	int tmpJ = 0, tmp1 = myMAX, tmp2 = myMAX, tmp3 = myMAX;//�ӽ������
	int tmpV1 = 0; int tmpV2 = 0, tmpV3 = 0, tmpV4 = 0;
	for(i = 0; i <= myMAX; i++){
		for(j = 0; j <= myMAX; j++){
			D[i][j] = myMAX;//�����Ⱚ���� �����Ͽ� ��� 1000���� �ʱ�ȭ��Ŵ
		}
	}
	for(i=2; i<= n ; i++){
		D[i][1] = W[i][1];//3,4,6,10�� ������
	}
	for(k=1; k<= n-2; k++){//k=1�϶� 4��, k=2�϶� 6��, k=3�϶� 4��
		for(int x = 2 ; x <= n-k+1 ; x++){//all subset A=V-v1 containing K vertices
			/*
			k = 1�϶� v2,v3,v4,v5
			k = 2�϶� (v2,v3),(v2,v4),(v2v5)(v3v4)(35)(45)
			k = 3�϶� (234)(235)(245)(345)
			*/
			for(i = x; i <= n; i ++ ){//i such that i != 1 and vi is not in A
				//�ӽú����� �ʱ�ȭ
				tmp1 = myMAX, tmp2 = myMAX, tmp3 = myMAX;
				if(i == x){
					//�ƹ��͵� ����..
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