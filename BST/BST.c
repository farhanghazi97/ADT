#include <stdio.h>
#include "BST.h"

int main (void) {

	//int input;

	printf("Enter values to create BST:\n");
	
	struct BSTreeNode * root_node = NULL; 
	
	struct BSTreeNode * BSTree = createBST(root_node);

	TraverseBST(BSTree , 0);

	//printf("Enter value to look for in tree: ");
	//scanf("%d" , &input);

	//BSTree = SearchBST(BSTree , input);
	//if (BSTree != NULL) {
	//	printf("Key found!\n");
	//} else {
	//	printf("Value does not exist within tree!\n");
	//}

	FreeBST(BSTree);

}