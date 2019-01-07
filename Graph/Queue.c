#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Queue.h"


Queue CreateNode (int value) {

	Queue new_queue = malloc(sizeof(Queue));
	new_queue->prev = NULL;
	new_queue->next = NULL;
	new_queue->value = value;
	new_queue->size = 0;
	return new_queue;

}

Queue CreateQueue (Queue head , int size) {

	int index = 1;
	int number = 0;

	while(index < size) {
		scanf("%d" , &number);
		Queue new_node = CreateNode(number);
		new_node->size++;
		index++;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	return head;

}

Queue Enqueue (Queue head , int number) {
	
	Queue new_node = CreateNode(number);
	head->size++;
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
}

int Dequeue (Queue head) {

	if(head->next == NULL) {
		int val = head->value;
		free(head);
		return val;
	}

	Queue curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	int temp = curr->value;
	curr->prev->next = NULL;
	free(curr);
	head->size--;
	return temp;

}

void PrintQueue (Queue head) {

	Queue curr = head;

	printf("\nTail : ");
	while(curr != NULL) {
		printf("%d <-> " , curr->value);
		curr = curr->next;
	}
	printf(": Front\n\n");

}

void FreeQueue (Queue head) {

	Queue curr = head;
	while(curr != NULL) {
		free(curr);
		curr = curr->next;
	}
}

void HelpInterface() {

	printf("\n<<<<<<<< HELP INTERFACE >>>>>>>>\n");
	printf("E = Enqueue an item into the queue\n");
	printf("D = Dequeue an item from the queue\n");
	printf("P = Print queue\n");
	printf("Q = Quit program\n");
	printf("H = See Help Interface\n");
	printf("<<<<<<<<<<<<<< END >>>>>>>>>>>>>\n\n");


}

int isqueueEmpty(Queue head) {

	return (head->size == 0);

}
