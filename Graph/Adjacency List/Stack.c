#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Stack.h"

Stack newStack (void) {
    Stack new_stack = malloc(sizeof(StackRep));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

SNode newSNode (int value) {
    SNode new_node = malloc(sizeof(StackNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Stack Push (Stack s , int value) {
    SNode new_node = newSNode(value);
    if(s->top == NULL) {
        s->top = new_node;
    } else {
        new_node->next = s->top;
        s->top = new_node;
    }
    s->size++;
    return s;
}

int Pop (Stack s) {
    assert(s != NULL);
    int vertex = 0;
    if(s->top != NULL) {
        SNode temp = s->top;
        vertex = s->top->value;
        s->top = s->top->next;
        free(temp);
        temp = NULL;
        s->size--;
    }
    return vertex;
}

void PrintStack(Stack s) {
    SNode curr = s->top;
    printf("Printing stack...\n");
    while(curr != NULL) {
        printf("%d | " , curr->value);
        curr = curr->next;
    }
    printf("\n");
}

bool StackIsEmpty(Stack s) {
    bool flag = false;
    if(s->size == 0) {
        flag = true;
    }
    return flag;
}

void FreeStack (Stack s) {
    free(s);
}
