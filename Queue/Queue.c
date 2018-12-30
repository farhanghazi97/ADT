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