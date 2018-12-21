#include <stdio.h>
#include "DLL.h"

int main(void) {

	int value;
	printf("Enter value of starting node: ");
	scanf("%d" , &value);
	
	struct node * head = create_DLL_node(value);

	int size;
	printf("Enter size of DLL list: ");
	scanf("%d" , &size);

	printf("Enter remaining nodes into list:\n");
	struct node * list = create_DLL_list(head , size);
	print_DLL_list(list);

	int index;
	int node;
	
	printf("Enter index to insert after: ");
	scanf("%d" , &index);
	
	printf("Enter value of node: ");
	scanf("%d" , &node);

	list = DLL_insert_after(list , index , node);
	print_DLL_list(list);

	printf("----- SANITY CHECK -----\n");

	int sum = sum_DLL(list);
	printf("Sum : %d\n" , sum);

	printf("Enter index to insert before: ");
	scanf("%d" , &index);

	printf("Enter value of node: ");
	scanf("%d" , &node);

	list = DLL_insert_before(list , index , node);
	print_DLL_list(list);

	printf("----- SANITY CHECK -----\n");

	sum = sum_DLL(list);
	printf("Sum : %d\n" , sum);

	printf("Enter a value to delete from the list: ");
	scanf("%d" , &node);

	list = delete_DLL_node(list , node);
	print_DLL_list(list);

	printf("----- SANITY CHECK -----\n");

	sum = sum_DLL(list);
	printf("Sum : %d\n" , sum);

	//traverse_list(list);

	free_DLL_list(list);

}