#include <stdio.h>
#include "DLL.h"

int main(void) {

	printf("\n <<<<<< DLL ADT INTERFACE >>>>> \n");

	int value;

	printf("\nEnter value of starting node: ");
	scanf("%d" , &value);
	
	struct node * head = create_DLL_node(value);

	int size;
	printf("Enter size of DLL list: ");
	scanf("%d" , &size);

	printf("Enter remaining nodes into list:\n\n");
	struct node * list = create_DLL_list(head , size);
	print_DLL_list(list);

	int index;
	int node;
	
	int operation = -1;

	printf("\nWelcome to the DLL Editor!");
	printf("\nEnter '7' to bring up the help interface");

	while(operation != 0) {


		printf("\nEnter operation: ");
		scanf("%d" , &operation);

		if (operation == 1) {
		
			printf("Enter index to insert after: ");
			scanf("%d" , &index);
		
			printf("Enter value of node: ");
			scanf("%d" , &node);

			list = DLL_insert_after (list , index , node);
			print_DLL_list (list);
		
		} else if (operation == 2) {
			
			printf("Enter index to insert before: ");
			scanf("%d" , &index);
			
			printf("Enter value of node: ");
			scanf("%d" , &node);

			list = DLL_insert_before (list , index, node);
			print_DLL_list (list);
		
		} else if (operation == 3) {
		
			printf("Enter a value to delete from the list: ");
			scanf("%d" , &node);

			list = delete_DLL_node (list , node);
			print_DLL_list (list);

		} else if (operation == 4) {

			traverse_list (list);

		} else if (operation == 5) {

			printf("\n");
			print_DLL_list (list);
			int sum = sum_DLL(list);
			printf("Sum : %d\n" , sum);
		
		} else if (operation == 6) {

			print_DLL_list (list);

		} else if (operation == 7) {

			print_interface();

		}

	}

	free_DLL_list(list);

}
