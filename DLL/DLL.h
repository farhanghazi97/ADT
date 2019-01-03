#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node * prev;
	struct node * next;
	int value;
};


// INTERFACE REFERENCE

// Indexes counted from 1 and onwards so when referencing insert 
// and delete position calling insert_after (head , 2 , 1000) on a list 
// such as [20 , 30 , 40 , 50 , 60] will return list as 
// [20 , 30 , 1000 , 40 , 50 , 60]

// Run with valgrind to conduct leak checks  

struct node * create_DLL_node   (int value);
struct node * create_DLL_list   (struct node * head , int size);
struct node * DLL_insert_before (struct node * head , int index , int value);
struct node * DLL_insert_after  (struct node * head , int index , int value);
struct node * delete_DLL_node   (struct node * head , int value);
void 	      print_DLL_list    (struct node * head);
void 	      traverse_list     (struct node * head);
void 	      free_DLL_list 	(struct node * head);
void          print_interface   ();
int 	      count_DLL_nodes   (struct node * head);
int 	      sum_DLL	        (struct node * head);
