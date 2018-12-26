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
	printf("Enter search term: ");
	scanf("%d" , &number);

	if(SearchBST(BSTree , number)) {
		printf("Value found !\n");
	} else {
		printf("Value not found !\n");
	}

	FreeBST(BSTree);

}
