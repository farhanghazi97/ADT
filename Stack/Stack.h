#include <stdlib.h>
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct StackRep * Stack;

typedef struct StackRep {

	int elems[MAX_ITEMS];
	int current_index;
	int top_elem_index;

} StackRep;

Stack InitializeStack (int data) ;
Stack Push 			  (Stack stack , int data);
Stack Pop 			  (Stack stack);
void  DisplayStack 	  (Stack stack);
void  FreeStack 	  (Stack stack);