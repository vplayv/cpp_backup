#include "stack.h"
void reset(stack* stk){//���� ����
	stk -> top = EMPTY;
}
void push(char c, stack* stk){//�������� ������ ����
	stk -> top++;
	stk -> s[stk -> top] = c;
}
char pop(stack* stk){//�������κ��� ������ ����
	return (stk -> s[stk -> top--]);
}
char top(const stack* stk){//������ ž�� Ȯ��
	return (stk -> s[stk ->top]);
}
bool empty(const stack* stk){//����ִ°�?
	return (stk -> top == EMPTY);
}
bool full(const stack* stk){//�� á�°�?
	return (stk -> top == FULL);
}