#include "stack.h"
void reset(stack* stk){//스택 리셋
	stk -> top = EMPTY;
}
void push(char c, stack* stk){//스택으로 데이터 삽입
	stk -> top++;
	stk -> s[stk -> top] = c;
}
char pop(stack* stk){//스택으로부터 데이터 삭제
	return (stk -> s[stk -> top--]);
}
char top(const stack* stk){//스택의 탑을 확인
	return (stk -> s[stk ->top]);
}
bool empty(const stack* stk){//비어있는가?
	return (stk -> top == EMPTY);
}
bool full(const stack* stk){//꽉 찼는가?
	return (stk -> top == FULL);
}