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
void 		  print_DLL_list    (struct node * head);
void 		  traverse_list     (struct node * head);
void 		  free_DLL_list 	(struct node * head);
int 		  count_DLL_nodes   (struct node * head);
int 		  sum_DLL			(struct node * head);

struct node * create_DLL_node (int value){

	struct node * new_node = malloc(sizeof(struct node *));
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	return new_node;
}

struct node * create_DLL_list(struct node * head , int size) {

	int index = 0;
	int number = 0;
	while(index < size) {
		scanf("%d" , &number);
		struct node * new_node = create_DLL_node(number);
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		index++;
	}
	printf("\nList successfully created...\n\n");
	return head;
}

void print_DLL_list(struct node * head) {

	struct node * curr = head;
	printf("X <-> ");
	while(curr != NULL) {
		printf("%d <-> " , curr->value);
		curr = curr->next;
	}
	printf("X\n");
}

void traverse_list (struct node * head) {

	char move;
	struct node * curr = head;
	printf("\nWelcome to the DLL Traverser!\n");
	printf("Enter 'H' to bring up the help menu\n\n");
	while((move  = getchar()) != 'E') {
		if (move == 'C') {
			printf ("Current : %d\n" , curr->value);
		} else if (move == 'F') {
			printf ("Moving foward....\n");
			curr = curr->next;
		} else if (move == 'N') {
			printf ("In front of current node : %d\n" , curr->next->value);
		} else if (move == 'P') {
			printf ("Behind current node : %d\n" , curr->prev->value);
		} else if (move == 'B') {
			printf("Moving backwards....\n");
			curr = curr->prev;
		} else if (move == 'H') {
			printf("-----INTERFACE HELP------\n");
			printf("C = print current node value\n");
			printf("F = move one node forward\n");
			printf("N = print value of node in front\n");
			printf("P = print value of  node behind\n");
			printf("B = move one node backward\n");
			printf("H = print help interface\n");
			printf("E = exit\n");
			printf("------------------------\n\n");
		} 
	}

}

void print_interface () {

	printf("\n-----INTERFACE HELP------\n");
	printf("0 = Exit DLL interface\n");
	printf("1 = Insert new node after given index\n");
	printf("2 = Insert new node before given index\n");
	printf("3 = Delete specified value from DLL\n");
	printf("4 = Use List Traverser\n");
	printf("5 = See help interface\n");
	printf("------------------------\n\n");

}

void free_DLL_list (struct node * head) {

	struct node * curr = head;
	while(curr != NULL) {
		free(curr);
		curr = curr->next;
	}

}

struct node * DLL_insert_after (struct node * head , int index , int value) {

	struct node * new_node = create_DLL_node(value);
	struct node * curr = head;
	int curr_index = 1;

	int elems = count_DLL_nodes(head);
	
	// HANDLES INVALID INSERT INDEX
	if (index > elems) {
		printf("Insert index exceeds list size\n");
		printf("Operation cancelled\n");
		return head;
	}

	// INSERT AT TAIL
	if (elems == index) {
		while(curr_index < index) {
			curr = curr->next;
			curr_index++;
		}
		//AT THIS POINT , CURR IS AT LAST NODE IN LIST
		curr->next = new_node;
		new_node->prev = curr;
		return head;
	}

	// INSERT INBETWEEN HEAD AND TAIL
	while(curr_index < index) {
		curr = curr->next;
		curr_index++;
	}

	curr->next->prev = new_node;
	new_node->next = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
	
	return head;
}

int count_DLL_nodes (struct node * head) {

	struct node * curr = head;
	int count = 0;
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

struct node * DLL_insert_before (struct node * head , int index , int value) {

	int elems = count_DLL_nodes(head);
	if (index > elems) {
		printf("Insert index exceeds list size\n");
		printf("Operation cancelled\n");
		return head;
	}

	struct node * new_node = create_DLL_node(value);
	struct node * curr = head;

	// INSERT AT HEAD
	if (index == 0 || index == 1) {
		curr->prev = new_node;
		new_node->next = curr;
		head = new_node;	
	}

	int curr_index = 1;
	while(curr_index < index) {
		curr = curr->next;
		curr_index++;
	}

	curr->prev->next = new_node;
	new_node->next = curr;
	curr->prev = new_node;
	new_node->prev = curr->prev;
	return head;

}

int sum_DLL	(struct node * head) {

	int running_sum = 0;
	struct node * curr = head;

	while(curr != NULL) {
		running_sum += curr->value;
		curr = curr->next;
	}
	return running_sum;
}

struct node * delete_DLL_node (struct node * head , int value) {

	//ASSUME NODE DOES NOT EXIST
	int found = 0;
	struct node * curr = head;
	while(curr != NULL) {
		if(curr->value == value) {
			found = 1;
		}
		curr = curr->next;
	}

	// HANDLES CASE WHERE VALUE DOES NOT EXIST WITHIN LIST
	if(found == 0) {
		printf("The value does not exist within the DLL\n");
		printf("Operation cancelled\n");
		return head;
	}

	// HANDLES CASE WHERE VALUE TO BE DELETED IS HEAD
	struct node * curr_head = head;
	if(curr_head->value == value) {
		//printf("Delete from head\n");
		head = curr_head->next;
		head->prev = NULL;
		free(curr_head);
		return head;
	}

	// HANDLES NODES TO BE DELETED BETWEEN HEAD AND TAIL
	struct node * traverse = head;
	while(traverse->value != value) {
		traverse = traverse->next;
	}
	
	// IF BLOCK CHECKS IF NODE TO BE DELETED FROM LIST
	// IS THE LAST NODE
	if(traverse->next == NULL) {
		//printf("CASE: Delete from tail\n");
		traverse->prev->next = NULL;
		free(traverse);
		return head;
	} else {
		traverse->prev->next = traverse->next;
		traverse->next->prev = traverse->prev;
		free(traverse);
		return head;
	}
}