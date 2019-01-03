#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "BST.h"

int main (void) {

	printf("\nEnter values to create BST:\n");
	printf("Enter -1 to stop insertion process\n\n");
	
	struct BSTreeNode * root_node = NULL; 
	
	struct BSTreeNode * BSTree = CreateBST(root_node);

	printf("\nCreating BST...\n");
	sleep(2);

	TraverseBST(BSTree , 0);
		
	int number;
	int operation = -1;
	
	while (operation != 0) {

		Action();
		printf("\nEnter op code: ");
		scanf("%d" , &operation);	

		if(operation == 1) {
			
			printf("\nEnter search term: ");
			scanf("%d" , &number);

			if(SearchBST(BSTree , number)) {
				printf("Value exists within tree !\n");
			} else {
				printf("Value not found !\n");
			}
	
		} else if (operation == 2) {

			printf("Enter a value to delete from the tree: ");
			scanf("%d" , &number);

			BSTree = DeleteBSTNode(BSTree , number);			

			TraverseBST (BSTree , 0);
		
		} else if (operation == 3) {

			struct BSTreeNode * max = FindMaxBST (BSTree);
			printf("Max : %d\n" , max->key);			

		} else if (operation == 4) {

			struct BSTreeNode * min = FindMinBST (BSTree);
			printf("Min : %d\n" , min->key);	

		}
	}	 

	FreeBST(BSTree);

}
