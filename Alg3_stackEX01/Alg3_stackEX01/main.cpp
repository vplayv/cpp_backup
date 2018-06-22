#include "stack.h"

int main(void){
	char str[] = "Stack Test";
	int i;
	stack s;
	reset(&s);
	printf("���ڿ� %s \n", str);
	for(i = 0; str[i] != '\0' ; i++)
		if(!full(&s))
			push(str[i], &s);
	printf("�� ���ڿ� : ");
	while(!empty(&s))
		putchar(pop(&s));
	putchar('\n');
	return 0;
}