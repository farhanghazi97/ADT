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

Queue Enqueue (Queue q , int value , int weight) {

    QNode start = q->head;
    QNode new_node = newQNode(value , weight);
    if(q->head == NULL) {
        q->head = new_node;
    } else if(q->head->weight > weight) {
        new_node->next = q->head;
        q->head = new_node;
    } else {
        while(start->next != NULL && start->next->weight < weight) {
            start = start->next;
        }
        new_node->next = start->next;
        start->next = new_node;
    }
    q->size++;
    return q;
}

int Dequeue (Queue q) {
    assert(q != NULL);
    QNode temp = q->head;
    int vertex = temp->value;
    q->head = q->head->next;
    q->size--;
    return vertex;
}

QNode newQNode (int value , int weight) {
    QNode new_node = malloc(sizeof(QueueNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

void PrintQueue (Queue q) {
    QNode curr = q->head;
    printf("Printing queue...\n");
    while(curr != NULL) {
        printf("%d - (%d) | " , curr->value , curr->weight);
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
    QNode curr = q->head;
    while(curr != NULL) {
        QNode temp = curr;
        free(temp);
        curr = curr->next;
    }
    free(q);
}
