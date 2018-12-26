#include <stdlib.h>
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct StackRep * Stack;

typedef struct StackRep {

	int elems[MAX_ITEMS];
	int current_index;
	int top_elem_index;

} StackRep;

Stack InitializeStack (int data) {

	Stack new_stack = malloc(sizeof(StackRep));
	new_stack->current_index = 0;
	new_stack->top_elem_index = MAX_ITEMS;
	new_stack->elems[new_stack->current_index] = data;
	return new_stack;

}

Stack Push (Stack stack , int data) {

	if(stack->current_index < MAX_ITEMS) {
		stack->current_index++;
		stack->top_elem_index = stack->current_index;
		stack->elems[stack->current_index] = data;
		return stack; 
	} else {
		printf("Stack is full!");
	}
	return stack;
}

Stack Pop (Stack stack) {

	stack->elems[stack->top_elem_index] = 0;
	stack->top_elem_index--; 
	return stack;
}

void DisplayStack (Stack stack) {

	printf("\nTOP : ");
	for(int i = stack->top_elem_index; i > 0; i--){
		printf("%d " , stack->elems[i]);
	}
	printf(": TAIL\n");

	printf("Top of stack : %d\n\n" , stack->elems[stack->top_elem_index]);

}

void FreeStack (Stack stack) {
	free(stack);
}
