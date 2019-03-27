#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "DLL.h"

typedef struct DLListRep {
    int size;
    DLListNode first;
    DLListNode curr;
    DLListNode last;
} DLListRep;

typedef struct DLLNode {
    char * value;
    DLListNode prev;
    DLListNode next;
} DLLNode;

DLList CreateDLList (void) {

    DLList list = NewDLList();

    char value[BUFSIZ];
    while(fgets(value , BUFSIZ , stdin) != NULL) {
        DLListNode new_node = NewDLListNode(value);
        if(list->last == NULL) {
            list->first = list->last = new_node;
        } else {
            list->last->next = new_node;
            new_node->prev = list->last;
            list->last = new_node;
        }
        list->size++;
    }
    list->curr = list->first;
    return list;
}

void InsertNodeAfter (DLList list , int index, char * value) {

    DLListNode new_node = NewDLListNode(value);

    if(index > list->size) {
        printf("Insert index exceeds list size\n");
        return;
    } else if(index < 1) {
        printf("Invalid insert index\n");
        return;
    }

    DLListNode curr = list->first;
    int curr_index = 1;
    if(index == list->size) {
        //ADD TO END OF LIST
        list->last->next = new_node;
        new_node->prev = list->last;
        list->last = new_node;
    } else {
        while(curr_index < index) {
            curr = curr->next;
            curr_index++;
        }
        //ADD BETWEEN HEAD AND TAIL
        new_node->prev = curr;
        new_node->next = curr->next;
        curr->next->prev = new_node;
        curr->next = new_node;
    }
    list->size++;
}


void InsertNodeBefore (DLList list , int index, char * value) {

    DLListNode new_node = NewDLListNode(value);

    if(index > list->size) {
        printf("Insert index exceeds list size\n");
        return;
    } else if(index < 1) {
        printf("Invalid insert index\n");
        return;
    }

    DLListNode curr = list->first;
    int curr_index = 1;

    if(index == 1) {
        //ADD BEFORE CURRENT HEAD (BECOMES NEW HEAD)
        new_node->prev = NULL;
        list->first->prev = new_node;
        new_node->next = list->first;
        list->first = new_node;
    } else {
        while(curr_index < (index - 1)) {
            curr = curr->next;
            curr_index++;
        }
        //ADD BETWEEN HEAD AND TAIL
        new_node->prev = curr;
        new_node->next = curr->next;
        curr->next->prev = new_node;
        curr->next = new_node;
    }
    list->size++;
}


DLList NewDLList (void) {
    DLList new_list = malloc(sizeof(DLListRep));
    if(new_list == NULL) printf("Could not allocate memory for list\n");
    new_list->size = 0;
    new_list->first = NULL;
    new_list->last = NULL;
    return new_list;
}

DLListNode NewDLListNode (char * value) {
    DLListNode new_node = malloc(sizeof(DLLNode));
    if(new_node == NULL) printf("Could not allocate memory for node\n");
    new_node->value = malloc(strlen(value) * sizeof(char));
    strncpy(new_node->value , value , strlen(value + 1));
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void PrintDLList(DLList list) {

    printf("First: %s\n" , list->first->value);
    printf("Last:  %s\n" , list->last->value);
    printf("Nodes: %d\n" , list->size);

    DLListNode curr = list->first;
    while(curr != NULL) {
        printf("%s <-> " , curr->value);
        curr = curr->next;
    }
    printf("X\n");

    /*curr = list->last;
    while(curr != NULL) {
        printf("%s <-> " , curr->value);
        curr = curr->prev;
    }
    printf("X\n");*/
}

void DLListNodeDelete(DLList list , int index) {

    DLListNode curr = list->first;
    int curr_index = 1;

    if(index == list->size) {
        // DELETE TAIL OF LIST
        DLListNode temp = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
        free(temp->value);
        free(temp);
        return;
    } else if(index == 1) {
        // DELETE HEAD OF LIST
        DLListNode temp = curr;
        list->first = curr->next;
        list->first->prev = NULL;
        free(temp->value);
        free(temp);
    } else {
        //DELETE INBETWEEN HEAD AND TAIL
        while(curr_index < index) {
            curr = curr->next;
            curr_index++;
        }
        DLListNode temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(temp->value);
        free(temp);
    }
    list->size--;
}

void FreeDLList (DLList list) {
    DLListNode curr = list->first;
    while(curr != NULL) {
        DLListNode temp = curr;
        free(temp->value);
        free(temp);
        curr = curr->next;
    }
    free(list);
}
