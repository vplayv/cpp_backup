#include <stdio.h>
#define Array1 10
#define Array2 10
int bin1(int n, int k);
int bin2(int n, int k);
int minimum(int i, int k);
int main(){
	//printf("bin1 조합 (%d,%d)\n", Array1, Array2);
	//printf("(%d,%d) : %d\n", Array1, Array2 , bin1(Array1,Array2));
	//printf("(%d,%d) : %d\n", 7, 3 , bin1(7,3));
	//printf("(%d,%d) : %d\n", 6, 2 , bin1(6,2));
	//printf("(%d,%d) : %d\n", 13, 7 , bin1(13,7));
	printf("bin2 조합 (%d,%d) 까지\n", Array1-3, Array2-3);
	int i =bin2(Array1,Array2);
	
 	return 0;
}
int minimum(int i, int k)
{
	if( i < k)
		return i;
	else
		return k;
}
int bin1(int n, int k){
	if(k==0 || n == k)
		return 1;
	else 
		return bin1(n-1,k-1) + bin1(n-1,k);
}
int bin2(int n, int k){
	int i = 0,j =0;
	int B[Array1][Array2] = {};
	for(i = 0 ; i < n ; i ++){
		for(j = 0; j < minimum(i,k); j++){
			if( (j ==0 ) || (j == 1))
				B[i][j] = 1;
			else
				B[i][j] = B[i-1][j-1] + B[i-1][j];
		}
	}
	printf("(%4d,%4d) : %d\n", Array1-3, Array2-3, B[Array1-1][Array2-2]);
	for(int i = 1; i < Array1 ; i++){
		for(int j = 1 ; j < Array2 ; j++){
			if(i > j)
				printf(" %d ",B[i][j]);
			if(i == j-1)
				printf("\n");
		}
	}
	return 0;
}