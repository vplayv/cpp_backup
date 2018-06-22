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
	struct bin3Array * myArray = (bin3Array*)malloc(sizeof(struct bin3Array) + sizeof(int) * ( (n*(n+1) / 2)));//플렉시블 배열 메모리 할당이다. 구조체 + 생성할 배열의 갯수만큼의 메모리 할당
	int plus = 1;
	int sumofN = (n*(n+1)) / 2 ;//총 갯수
	for(int i = 0 ; i < (n*(n+1)) / 2 ; i = i + (plus++)){//시작 지점이 0, 1, 3, 6, 10 ...
		for(int j = i ; j < (i+plus) ; j++){//1개 ,2개, 3개로 늘어나는 이항계수
			if( j == i)
				myArray -> B[j] = 1;//조합 (x,0)은 1이기때문에
			else if (j == (i + plus -1))
				myArray -> B[j] = 1;//조합 (x,x)는 1이기 때문에
			else
				myArray -> B[j] = myArray -> B[j-plus] + myArray -> B[j-plus+1];//(x,n) == (x-1,n-1) + (x-1,n)이기 때문에
		}
	}
	for(int f = 0; f < (n*(n+1)) / 2 ; f++){
		printf(" %d " , myArray -> B[f]);
	}
	printf("\n(%d,%d) = %d", n, k, myArray -> B[sumofN -1 - (n-k)]);//(n,k) 출력
	return 0;
}