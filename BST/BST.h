#include <stdio.h>
#include <stdlib.h>

#define COUNT 5

struct BSTreeNode {
	int key;
	struct BSTreeNode * left;
	struct BSTreeNode * right;
};

struct BSTreeNode * create_node (int value) {

	struct BSTreeNode * new_node = malloc(sizeof(struct BSTreeNode *));
	new_node->key = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct BSTreeNode * InsertBSTNode(struct BSTreeNode * root , int key) {

	if(root == NULL){
		struct BSTreeNode * new_node = create_node(key);
		return new_node;
	} else if(key < root->key) {
		return InsertBSTNode(root->left , key);
	} else if(key > root->key) {
		return InsertBSTNode(root->right , key);
	} else {
		return root;
	}
	return root;
}

void traverse_BST (struct BSTreeNode * root , int space) {

	if(root == NULL) {
		return;
	}

	space += COUNT;

	traverse_BST(root->right , space);
	
	printf("\n");
	for(int i = COUNT; i < space; i++){
		printf(" ");
	}
	printf("%d\n" , root->key);
	
	traverse_BST(root->left , space);

}

void FreeBST(struct BSTreeNode * root) {

	if(root != NULL){
		FreeBST(root->right);
		FreeBST(root->left);
		free(root);
	}
}
