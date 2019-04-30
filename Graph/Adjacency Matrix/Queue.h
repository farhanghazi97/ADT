#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRep * Queue;

typedef struct QueueRep {

	int value;
	int size;
	Queue next;
	Queue prev;

} QueueRep;

Queue CreateNode   (int value);
Queue CreateQueue  (Queue head , int size);
Queue Enqueue      (Queue head , int number);
void  PrintQueue   (Queue head);
void  FreeQueue    (Queue head);
int   Dequeue      (Queue head);
int   isqueueEmpty (Queue head);

