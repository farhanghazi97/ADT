#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRep * Queue;

typedef struct QueueRep {

	int value;
	Queue next;
	Queue prev;

} QueueRep;

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