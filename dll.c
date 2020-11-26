#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dll.h"
#define MAX_LENGTH 10

typedef struct DLListRep {
	int size;
	DLLNode head;
	DLLNode curr;
	DLLNode tail;
} DLListRep;

typedef struct DLListNode {
	char * value;
	DLLNode prev;
	DLLNode next;
} DLListNode;

DLList newDLL() {
	DLList newList = malloc(sizeof(DLListRep));
	if (newList == NULL) printf("Error!");
	newList->size = 0;
	newList->head = NULL;
	newList->curr = NULL;
	newList->tail = NULL;
	return newList;
}

DLLNode newDLLNode(char * value) {
	DLLNode newNode = malloc(sizeof(DLListNode));
	newNode->value = malloc(strlen(value) * sizeof(char));
	strncpy(newNode->value, value, strlen(value + 1));
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

DLList constructDLL() {

	DLList DLL = newDLL();
	char str [MAX_LENGTH];
	while(fgets(str, MAX_LENGTH, stdin) != NULL) {
		DLLNode newNode = newDLLNode(str);
		if(DLL->tail == NULL) {
			DLL->head = DLL->tail = newNode;
		} else {
			DLL->tail->next = newNode;
			newNode->prev = DLL->tail;
			DLL->tail = newNode;
		}
		DLL->size++;
	}
	return DLL;

}

int main(void) {
	
	DLList list = constructDLL();
	DLLNode curr = list->head;
	while(curr != NULL) {
		printf("%s -> " , curr->value);
		curr = curr->next;
	}


}


