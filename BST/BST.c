#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "BST.h"

int main (void) {

	printf("\nEnter values to create BST:\n");
	printf("Enter Ctrl + D to stop insertion process\n\n");
	
	struct BSTreeNode * root_node = NULL; 
	
	struct BSTreeNode * BSTree = CreateBST(root_node);

	printf("\nCreating BST...\n");
	sleep(2);

	TraverseBST(BSTree , 0);
		
	if(SearchBST(BSTree , 100)) {
		printf("Value found !\n");
	} else {
		printf("Value not found !\n");
	}

	FreeBST(BSTree);

}
