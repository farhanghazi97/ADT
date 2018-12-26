#include <stdio.h>
#include <unistd.h>
#include "Stack.h"

int main(void) {

	printf("Start adding elements onto the stack.\n");
	printf("Enter Ctrl + D to stop adding elements.\n");
	printf("By default the stack size is 10\n\n");

	int number;
	Stack my_stack = InitializeStack(0);
		
	while(scanf("%d" , &number) != EOF) {
		my_stack = Push (my_stack , number);
		DisplayStack(my_stack);
	}

	printf("Now we pop elements off stack....\n");

	while (my_stack->top_elem_index >= 0) {
		Pop(my_stack);
		sleep(1);
		DisplayStack(my_stack);	
	}
	FreeStack(my_stack);
}
