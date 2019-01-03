#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRep * Queue;

typedef struct QueueRep {

	int value;
	Queue next;
	Queue prev;

} QueueRep;

Queue CreateNode    (int value);
Queue CreateQueue   (Queue head , int size);
Queue Enqueue       (Queue head);
Queue Dequeue       (Queue head);
void  PrintQueue    (Queue head);
void  FreeQueue     (Queue head);
void  HelpInterface ();