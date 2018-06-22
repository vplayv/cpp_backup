#include <stdio.h>
#include <stdlib.h>
#define myN 10			//������ ���� 10��
#define myMax 1000		//���Ѵ�
#define myEdgeNumber 13	//�𼭸��� ���� 13��
struct Edge
{
	int start;	//���� ����
	int arrival;//���� ����
	int weight;	//����ġ
};
typedef struct Edge Edge;
typedef struct Edge* Edge_pointer;
const int W[myN][myN] =
{
	{0,32,myMax,17,myMax,myMax,myMax,myMax,myMax,myMax},
	{32,0,myMax,myMax,45,myMax,myMax,myMax,myMax,myMax},
	{myMax,myMax,0,18,myMax,myMax,5,myMax,myMax,myMax},
	{17,myMax,18,0,10,myMax,myMax,3,myMax,myMax},
	{myMax,45,myMax,10,0,28,myMax,myMax,25,myMax},
	{myMax,myMax,myMax,myMax,28,0,myMax,myMax,myMax,6},
	{myMax,myMax,5,myMax,myMax,myMax,0,59,myMax,myMax},
	{myMax,myMax,myMax,3,myMax,myMax,59,0,4,myMax},
	{myMax,myMax,myMax,myMax,25,myMax,myMax,4,0,12},
	{myMax,myMax,myMax,myMax,myMax,6,myMax,myMax,12,0},
};
int F[myN -1][3] = {};//[0] = v(f), [1] = v{L}, [2] = weight  => F[9][3]
//�Լ� ����
bool equal(bool p[][myN], bool q[][myN]);
void kruskal();
void merge(bool p[][myN], bool q[][myN]);

bool equal(bool p[][myN], bool q[][myN]){
	for(int i = 0; i < myN ; i++){
		for(int j = 0 ; j < myN ; j++){
			if(p[i][j] != q[i][j]){
				return false;
			}
		}
	}
	return true;
}
void merge(bool p[][myN], bool q[][myN]){
	for(int i = 0; i < myN ; i ++){
		for(int j = 0 ; j < myN ; j++){
			if( (p[i][j] || q[i][j]) == true){
				p[i][j] = true;
				q[i][j] = true;
			}
		}
	}
}
void kruskal()
{
	int i,j;// index
	int k = 0, t = 0;// k�� F�� �ε���, t�� E�� �ε���
	bool p[myN][myN] = {
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	};//set pointer p ���� p�� bool p[10] ���� ������ ����

	bool q[myN][myN] = {
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	{false,false,false,false,false,false,false,false,false,false},
	};//set pointer q ���� q�� bool q[10] ���� ������ ����
	bool p_number[myN] = {false,false,false,false,false,false,false,false,false,false};//P�迭�� ���Ե� ������
	bool q_number[myN] = {false,false,false,false,false,false,false,false,false,false};//Q���տ� ���Ե� ������
	Edge_pointer e, tmpEdge;
	Edge_pointer E[myEdgeNumber];//�𼭸� �迭 ������
	e = (Edge_pointer)malloc(sizeof(Edge));
	tmpEdge = (Edge_pointer)malloc(sizeof(Edge));
	for(i = 0; i < myEdgeNumber ; i++)
		E[i] = (Edge_pointer)malloc(sizeof(Edge));//���� �޸� �Ҵ�
	i = 0; //�ε���
	for(int m= 0; m < myN ; m++)//�� ���ĵ� ������ �𼭸� �迭 �ʱ�ȭ �ϱ�
	{
		for(int n = 0; n < myN ; n++)
		{
			if(W[m][n] > 0 && W[m][n] < myMax && m <= n)
			{
				E[i] -> start = m;	//m = v(F)
				E[i] -> arrival = n;//n = v(L)
				E[i] -> weight = W[m][n]; //����ġ ����
				i++;
			}
		}
	}
	printf("���� �� E�迭 ���\n");
	for(i = 0; i < myEdgeNumber ; i++){//����Ʈ Ȯ�ο�
		printf(" E[%d] : (V%d, V%d) = %d \n",i,E[i] ->start+1, E[i] -> arrival+1, E[i] -> weight);
	}
	//Sort the m(13��) edges in E by weight in nondecreasing order = ���� ���� ��ȯ ����
	for(i = 0; i < myEdgeNumber ; i ++){
		for(j = i+1; j < myEdgeNumber ; j++){
			if(E[i] -> weight > E[j] -> weight){
				tmpEdge -> start = E[i] -> start;
				tmpEdge -> arrival = E[i] -> arrival;
				tmpEdge -> weight = E[i] -> weight;
				E[i] -> start = E[j]  -> start;
				E[i] -> arrival = E[j]  -> arrival;
				E[i] -> weight = E[j]  -> weight;
				E[j] -> start= tmpEdge-> start;
				E[j] -> arrival= tmpEdge-> arrival;
				E[j] -> weight = tmpEdge -> weight;
			}
		}
	}
	printf("���� �� E�迭 ���\n");
	for(i = 0; i < myEdgeNumber ; i++){//����Ʈ Ȯ�ο�
		printf(" E[%d] : (V%d, V%d) = %d \n",i,E[i] ->start+1, E[i] -> arrival+1, E[i] -> weight);
	}
	bool tmpCheck1, tmpCheck2;//üũ
	while(k < myN-1 && t < myEdgeNumber){
		tmpCheck1 = false;
		tmpCheck2 = false;
		printf(" E[%d] : (V%d, V%d) = %d \n",t,E[t] ->start+1, E[t] -> arrival+1, E[t] -> weight);
		e ->arrival = E[t] ->arrival;
		e ->start = E[t] ->start;
		e ->weight = E[t] ->weight;
		i = e ->start;//VF
		j = e ->arrival;//VL
		p[i][j] = true;// [VF][VL] ��°�� true
		q[j][i] = true;// [VL][VF] ��°�� true
		p_number[i] = true;
		q_number[j] = true;
		for(int tmp1 = 0; tmp1 < myN ; tmp1++){
			if(p_number[tmp1] == true){
				if(p[tmp1][i] == true)
					tmpCheck1 = true;
			}
		}
		for(int tmp1 = 0; tmp1 < myN ; tmp1++){
			if(q_number[tmp1] == true){
				if(q[tmp1][j] == true)
					tmpCheck2 = true;
			}
		}
		printf("P�迭 \n");
		for(int m = 0; m < myN ; m++){
			for(int n = 0; n < myN ; n++){
				if(p[m][n] == true){
					printf("(V%d,V%d) ",m+1, n+1);
				}
			}
		}
		printf("\nQ �迭\n");
		for(int m = 0; m < myN ; m++){
			for(int n = 0; n < myN ; n++){
				if(q[m][n] == true){
					printf("(V%d,V%d) ",m+1, n+1);
				}
			}
		}
		printf("\n");
		if(!equal(p,q) && !(tmpCheck1 && tmpCheck2)){
		//	p_number[j] = true;
		//	q_number[i] = true;
			merge(p,q);
			F[k][0] = e -> start;// VF �� 0
			F[k][1] = e -> arrival;// VL �� 1
			F[k][2] = e -> weight;//����ġ
			k++;
		}
		else{

		}
		t++;
	}
	for(i = 0; i < myN - 1; i++){
		if(F[i][2] != 0)
		{
		printf("%d��° ���� : (V%d,V%d) = %d \n", i+1, F[i][0]+1, F[i][1]+1, F[i][2]);
		}
	}
}

int main(){
	kruskal();
	return 0;
}