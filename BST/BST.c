#include <stdio.h>
#include "BST.h"

int main (void) {

	printf("Enter values to create BST:\n");
	
	struct BSTreeNode * root_node = NULL; 
	
	struct BSTreeNode * BSTree = createBST(root_node);

	TraverseBST(BSTree , 0);

	FreeBST(BSTree);

}