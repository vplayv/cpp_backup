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
			cout<<"������ ���"<<endl;
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
	int i = 0, j;//�ε���
	int m = 1, mprod = 1, numnodes = 1;//Int
	int promising_children[myN+1] = {-1,0,0,0,0,0,0,0,0};//set of index promising_children
	while(m != 0 && i != n){
		mprod = mprod * m;
		numnodes = numnodes + mprod*n;
		i++;
		m = 0;
		for(int k = 1 ; k <= myN ; k++)
			promising_children[k] = -1;//promising_childeren = ������;
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
			cout<<"�� m :"<<m<<", ���� ���õ� tmp�� : "<<tmp<<", j : "<<j<<endl;
			col[i] = j;
		}
	}
	return numnodes;
};
int main(){
//	queens(0);
	srand(time(NULL));//���� �õ带 ���Ѱ�
	int result = estimate_n_queens(8);
	cout <<"��� ��(����� ����) : "<<result<<"��"<<endl;
	return 0;
}