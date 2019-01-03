#include <stdio.h>
#include <unistd.h>
#include "Queue.h"

int main(void) {

	int size;
	printf("\nEnter size of queue: ");
	scanf("%d" , &size);

	int value;

	printf("\nEnter values into queue:\n\n");
	scanf("%d" , &value);

	Queue queue = CreateNode(value);
	queue = CreateQueue(queue , size);

	printf("\nCreating queue...\n");
	sleep(2);

	PrintQueue(queue);

	HelpInterface();

	char operation = 0;
	while(operation != EOF) {
		operation = getchar();
		if(operation == 'E') {
			queue = Enqueue(queue);
			PrintQueue(queue);
		} else if (operation == 'D') {
			queue = Dequeue(queue);
			PrintQueue(queue);
		} else if (operation == 'Q') {
			break;
		} else if (operation == 'H') {
			HelpInterface();
		} else if (operation == 'P') {
			PrintQueue(queue);
		}
	}

	FreeQueue(queue);

}

Queue CreateNode (int value) {

	Queue new_queue = malloc(sizeof(Queue));
	new_queue->prev = NULL;
	new_queue->next = NULL;
	new_queue->value = value;
	return new_queue;

}

Queue CreateQueue (Queue head , int size) {

	int index = 1;
	int number = 0;

	while(index < size) {
		scanf("%d" , &number);
		Queue new_node = CreateNode(number);
		index++;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	return head;

}

Queue Enqueue (Queue head) {

	int number;
	
	printf("\nEnter number to enqueue: ");
	scanf("%d" , &number);
	
	Queue new_node = CreateNode(number);

	new_node->next = head;
	head->prev = new_node;
	head = new_node;
}

Queue Dequeue (Queue head) {

	if (head == NULL) {
		return NULL;
	}

	Queue curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->prev->next = NULL;
	free(curr);
	return head;

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