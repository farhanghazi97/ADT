#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Queue.h"

Queue newQueue(void){
    Queue new_queue = malloc(sizeof(QueueRep));
    assert(new_queue != NULL);
    new_queue->size = 0;
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

Queue Enqueue (Queue q , int value) {
    QNode new_node = newQNode(value);
    if(q->head == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
    return q;
}

int Dequeue (Queue q) {\
    int vertex = 0;
    if(q->size == 1) {
        QNode temp = q->tail;
        vertex = q->tail->value;
        free(temp);
        q->head = q->tail = NULL;
        q->size--;
    } else {
        QNode temp = q->head;
        vertex = q->head->value;
        q->head = q->head->next;
        free(temp);
        temp = NULL;
        q->size--;
    }
    return vertex;
}

QNode newQNode (int value) {
    QNode new_node = malloc(sizeof(QueueNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void PrintQueue (Queue q) {
    QNode curr = q->head;
    printf("Printing queue...\nSize : %d\n" , q->size);
    while(curr != NULL) {
        printf("%d | " , curr->value);
        curr = curr->next;
    }
    printf("\n");
}

bool QueueIsEmpty (Queue q) {
    bool flag = false;
    if(q->size == 0) {
        flag = true;
    }
    return flag;
}

void FreeQueue (Queue q) {
    free(q);
}
