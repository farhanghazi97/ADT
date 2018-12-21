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


struct node * create_node (int value) {

 	struct node * new_node = malloc(sizeof(struct node *));
 	new_node->next = NULL;
 	new_node->value = value;
 	return new_node;
}

struct node * create_list (struct node * head , int size) {

	int value;
	int input = 1;
	while(input < size) {
		scanf("%d" , &value);
		struct node * new_node = create_node(value);
		new_node->next = head;
		head = new_node;
		input++;
	}
	return head;
}

struct node * delete_element(struct node * head , int value) {

	struct node * check = head;

	int found = 0;
	while(check != NULL) {
		if (check->value == value) {
			found = 1;
			break;
		} 
		check = check->next;
	}

	if (found == 0) {
		printf("\nValue does not exist within list\n");
		printf("Operation cancelled\n\n");
		return head;
	}

	struct node * curr = head;
	struct node * curr_front = head->next;

	if (curr->value == value) {
		struct node * new_head = curr->next;
		head = new_head;
		free(curr);
		return head;
	}

	while(curr->next->value != value) {
		curr_front = curr_front->next;
		curr = curr->next;
	}
	curr->next = curr_front->next;
	free(curr_front);
	return head;
}

struct node * insert_after(struct node * head , int pos , int value) {

	int elems = count_elem(head);

	int index = 1;
	struct node * new_node = create_node(value);
	struct node * curr = head;

	if(pos > elems) {
		printf("\nThere is no %dth element to insert after\n" , pos);
		printf("Insert position exceeds list size.\n");
		printf("Operation cancelled.\n\n");
		return head;
	}

	if (pos > 0) {
		while(index != pos) {
			curr = curr->next;
			index++;
		}
		new_node->next = curr->next;
		curr->next = new_node;
	} else if (pos == 0) {
		head = new_node;
		new_node->next = curr;
	} else if (pos < 0) {
		printf("\nInvalid insert position!\n");
	} else {
		printf("\nInvalid input!");
	}
	return head;
}


struct node * insert_before (struct node * head , int pos , int value) {

	struct node * new_node = create_node(value);
	struct node * curr = head;
	struct node * curr_front = head->next;
	pos--;

	int elems = count_elem(head);

	if(pos >= elems) {
		printf("\nThere is no %dth element to insert before.\n" ,( pos + 1));
		printf("Insert position exceeds list size.\n");
		printf("Operation cancelled.\n");
	}

	// INSERT AT HEAD
	if (pos == 0) {
		new_node->next = curr;
		head = new_node;
		return head;
	}

	// INSERT INBETWEEN HEAD AND TAIL INCLUDING TAIL
	int index = 1;
	while(index < pos) {
		curr = curr->next;
		curr_front = curr_front->next;
		index++;
	}
	curr->next = new_node;
	new_node->next = curr_front;
	return head;
}

int sum_linked_list (struct node * head) {

	int sum = 0;
	struct node * curr = head;
	while(curr != NULL) {
		sum += curr->value;
		curr = curr->next;
	}
	return sum;
}

int count_elem (struct node * head) {

	int count = 0;
	struct node * curr = head;
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

void print_list (struct node * head) {

	struct node * curr = head;
	printf("Head : ");
	while(curr != NULL){
		printf("%d " , curr->value);
		curr = curr->next;
	}
	printf(" : Tail\n");
	printf("\n");

}

void free_list(struct node * head) {

	struct node * curr = head;
	while(curr != NULL) {
		free(curr);
		curr = curr->next;
	}
}
