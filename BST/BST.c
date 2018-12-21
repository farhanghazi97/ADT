#include <stdio.h>
#include "BST.h"

int main (void) {

	
	int value;
	printf("Enter value for root node: ");
	scanf("%d" , &value);
	
	//printf("Root node : %d\n" , root_node->key);
	struct BSTreeNode * root_node = create_node(value);
	root_node->left  = create_node(20);
	root_node->right = create_node(30);
	root_node->left->left = create_node(40);
	root_node->right->left = create_node(50);
	root_node->right->left->right = create_node(5);
	root_node->left->left->right = create_node(3);

	traverse_BST(root_node , 0);
	FreeBST(root_node);

	return 0;
}