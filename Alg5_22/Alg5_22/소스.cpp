#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#define myN 6
#define infi 9999
/*
	1. 이것은 22번이므로 노드는 6개다.
	2. 또한 스트링으로 한다.
	3. C++의 cstring을 이용함
*/
using namespace std;
struct myNode{
	char* key;
	myNode* left;
	myNode* right;
};//노드 구조체

//========함수 목록==========================
void opt(int n, float& minavg);//옵티멀 함수
myNode* tree(int i , int j, int depth);//트리 만드는 함수

//========미리 지정된 배열 목록==============
float myGameArray[myN+1] = {0, 0.05, 0.15, 0.05, 0.35, 0.05, 0.35};//미리 설정된 확률
char myKeyArray[myN+1][5] = {"","CASE","ELSE","END","IF","OF","THEN"};//키값
float A[myN+1 + 1][myN + 1] = {0};//미리 지정된 12*11 행렬 A (1~n+1,0~n)
int R[myN+1 + 1][myN + 1] = {0};//미리 지정된 12*11 행렬 P (1~n+1,0~n)
int main(){
	float resultAVG = 0;//AVG값
	opt(6, resultAVG);
	myNode* myTree = NULL;
	myTree = tree(1,6, 1);
	return 0;
}
void opt(int n, float& minavg){//n은 무조건 10
	int i = 0, j = 0, k = 0, diagonal = 0, tmpK =0;
	float tmp1 = 0, tmp2 = 0, tmp3 = infi, tmpSum = 0;//임시 K저장용
	for(i = 1; i <= n; i++){
		A[i][i-1] = 0;
		A[i][i] = myGameArray[i];
		R[i][i] = i;
		R[i][i-1] = 0;
	}
	A[n+1][n] = 0;
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
			A[i][j] = tmp3 + tmpSum;//A = min()+sigmaP
			R[i][j] = tmpK;//최소의 숫자일때의 K
		}
	}
	minavg = A[1][n];
	printf("A[][]출력\n");
	printf("      %6d%5d%5d%6d%6d%6d%6d\n",0,1,2,3,4,5,6);
	for(i = 1; i <myN + 2; i++){
		printf("%6d ",i);
		for(j = 0; j < myN + 1; j++){
			printf(" %5.2f", A[i][j]);
			if(j == myN)
				printf("\n");
		}
	}
	printf("P[][]출력\n");
	printf("      %4d%4d%4d%4d%4d%4d%4d\n",0,1,2,3,4,5,6);
	for(i = 1; i <myN + 2; i++){
		printf("%6d ",i);
		for(j = 0; j < myN + 1; j++){
			printf("%4d", R[i][j]);
			if(j == myN)
				printf("\n");
		}
	}
	printf("MINAVG = %.2f\n", minavg);
}

myNode* tree(int i, int j, int depth){
	int k;
	myNode* p;
	int thislevel = depth;
	k = R[i][j];
	if(k == 0)
		return 0;
	else{
		p = (myNode*)malloc(sizeof(myNode)+100);
		p->key = new char[10];
		strcpy_s(p->key,9,myKeyArray[k]);
		for(int u = 1; u <= thislevel; u++){
			printf("   ");
		}
		//printf("%d\n", k);
		printf("%s\n", myKeyArray[k]);
		++thislevel;
		p -> left = tree(i, k-1, thislevel);
		p -> right = tree(k+1, j, thislevel);
		return p;
	}
}

/*
//http://leetcode.com/2010/09/how-to-pretty-print-binary-tree.html
// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}
 
// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}
 
// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << endl;
}
 
// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(BinaryTree *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;
 
  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<BinaryTree*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
 
    for (int i = 0; i < nodesInThisLevel; i++) {
      BinaryTree *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
       nodesQueue.push_back(currNode->left);
       nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}
*/