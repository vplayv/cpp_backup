#include <stdio.h>
#include <stdlib.h>
struct bin3Array{
	int B[];
};
int bin3(int n, int k);
int main(){
	bin3(10,6);
 	return 0;
}
int bin3(int n, int k){
	struct bin3Array * myArray = (bin3Array*)malloc(sizeof(struct bin3Array) + sizeof(int) * ( (n*(n+1) / 2)));//�÷��ú� �迭 �޸� �Ҵ��̴�. ����ü + ������ �迭�� ������ŭ�� �޸� �Ҵ�
	int plus = 1;
	int sumofN = (n*(n+1)) / 2 ;//�� ����
	for(int i = 0 ; i < (n*(n+1)) / 2 ; i = i + (plus++)){//���� ������ 0, 1, 3, 6, 10 ...
		for(int j = i ; j < (i+plus) ; j++){//1�� ,2��, 3���� �þ�� ���װ��
			if( j == i)
				myArray -> B[j] = 1;//���� (x,0)�� 1�̱⶧����
			else if (j == (i + plus -1))
				myArray -> B[j] = 1;//���� (x,x)�� 1�̱� ������
			else
				myArray -> B[j] = myArray -> B[j-plus] + myArray -> B[j-plus+1];//(x,n) == (x-1,n-1) + (x-1,n)�̱� ������
		}
	}
	for(int f = 0; f < (n*(n+1)) / 2 ; f++){
		printf(" %d " , myArray -> B[f]);
	}
	printf("\n(%d,%d) = %d", n, k, myArray -> B[sumofN -1 - (n-k)]);//(n,k) ���
	return 0;
}