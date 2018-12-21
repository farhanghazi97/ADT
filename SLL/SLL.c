#include <stdio.h>
#include "SLL.h"

int main(void) {
	
	int start_node;
	int length;
	printf("Enter size of linked list: ");
	scanf("%d" , &length);
	printf("Enter values to create linked list:\n\n");
	scanf("%d" , &start_node);

	struct node * head = create_node(start_node);
	struct node * list = create_list(head , length);
	
	printf(" ----- TEST DELETE -----\n\n");
	
	int delete_val;
	printf("Enter value to be deleted from list: ");
	scanf("%d" , &delete_val);

	list = delete_element(list , delete_val);
	print_list(list);

	printf(" ----- SANITY CHECK -----\n\n");

	int sum = sum_linked_list(list);
	printf("Sum : %d\n\n" , sum);		

	printf(" ----- TEST INSERT AFTER GIVEN INDEX -----\n\n");

	int insert_pos;
	int insert_val;
	printf("Enter an index to insert in front of: ");
	scanf("%d" , &insert_pos);
	printf("Enter value of node: ");
	scanf("%d" , &insert_val);

	list = insert_after(list , insert_pos , insert_val);
	print_list(list);	

	printf(" ----- SANITY CHECK -----\n\n");

	sum = sum_linked_list(list);
	printf("Sum : %d\n\n" , sum);	

	printf(" ----- TEST INSERT BERFORE INDEX -----\n\n");

	printf("Enter an index to insert before: ");
	scanf("%d" , &insert_pos);
	printf("Enter value of node: ");
	scanf("%d" , &insert_val);

	list = insert_before(list , insert_pos , insert_val);
	print_list(list);	

	printf(" ----- SANITY CHECK -----\n\n");

	sum = sum_linked_list(list);
	printf("Sum : %d\n\n" , sum);

	free_list(list);


}
