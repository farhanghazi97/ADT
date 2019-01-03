#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node * next;
	int value;
};

// INTERFACE REFERENCE

// Indexes counted from 1 and onwards so when referencing insert 
// and delete position calling insert_after (head , 2 , 1000) on a list 
// such as [20 , 30 , 40 , 50 , 60] will return list as 
// [20 , 30 , 1000 , 40 , 50 , 60]

// Run with valgrind to conduct leak checks  

struct node * create_node     (int value);
struct node * create_list     (struct node * head , int size);
struct node * delete_element  (struct node * head , int value);
struct node * insert_after    (struct node * head , int pos , int value);
struct node * insert_before   (struct node * head , int pos , int value);
int  	      sum_linked_list (struct node * head);
int  	      count_elem      (struct node * head);
void 	      print_list      (struct node * head);
void 	      free_list       (struct node * head);
