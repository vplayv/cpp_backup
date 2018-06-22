#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define myN 8
/*
	Implement algorithm 5.3 on your system, run it 20 times on the problem instance in which n = 8, and find average of the 20 estimates.
*/
using namespace std;

void queens(int);
int estimate_n_queens(int);
bool promising(int);
int col[myN+1];

void queens(int i){
	int j;
	if(promising(i)){
		if(i == myN){
			cout<<"유망한 목록"<<endl;
			for(j = 1; j <= myN ; j++){
				cout<<"("<<j<<") : "<<col[j]<<" "<<endl;
			}
		}
		else{
			for(j = 1; j <= myN ; j++){
				col[i+1] = j;
				queens(i+1);
			}
		}
	}
}
bool promising(int i){
	int k;
	bool check1;
	k = 1;
	check1 = true;
	while(k<i && check1){
		if(col[i] == col[k] || abs(col[i] - col[k]) == abs(i-k))
			check1 = false;
		k++;
	}
	return check1;
}
int estimate_n_queens(int n){
	int i = 0, j;//인덱스
	int m = 1, mprod = 1, numnodes = 1;//Int
	int promising_children[myN+1] = {-1,0,0,0,0,0,0,0,0};//set of index promising_children
	while(m != 0 && i != n){
		mprod = mprod * m;
		numnodes = numnodes + mprod*n;
		i++;
		m = 0;
		for(int k = 1 ; k <= myN ; k++)
			promising_children[k] = -1;//promising_childeren = 공집합;
		for(j = 1; j <= n ; j++){
			col[i] = j;
			if(promising(i)){
				m++;
				promising_children[m] = j;
				//promising_children = promising_children U {j};
			}
		}
		if(m != 0){
			// j = random selection from promising_children;
			int tmp = rand() % m + 1;
			j = promising_children[tmp];
			cout<<"총 m :"<<m<<", 그중 선택된 tmp값 : "<<tmp<<", j : "<<j<<endl;
			col[i] = j;
		}
	}
	return numnodes;
};
int main(){
//	queens(0);
	srand(time(NULL));//랜덤 시드를 위한것
	int result = estimate_n_queens(8);
	cout <<"결과 값(노드의 갯수) : "<<result<<"개"<<endl;
	return 0;
}