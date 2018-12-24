#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 3 

struct BSTreeNode {
	int key;
	struct BSTreeNode * left;
	struct BSTreeNode * right;
};

struct BSTreeNode * create_node (int value);
struct BSTreeNode * CreateBST(struct BSTreeNode * root);
struct BSTreeNode * InsertBSTNode(struct BSTreeNode * root , int key);
bool   SearchBST (struct BSTreeNode * root , int search_val);
void   TraverseBST  (struct BSTreeNode * root , int space);
void   FreeBST      (struct BSTreeNode * root);

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
		root->left = InsertBSTNode(root->left , key);
	} else {
		root->right =  InsertBSTNode(root->right , key);
	}
	return root;
}

	
struct BSTreeNode * CreateBST(struct BSTreeNode * root) {

	int input;
	while(scanf(" %d" , &input) != EOF) {
		root = InsertBSTNode(root , input);
	}

	return root;
}

void TraverseBST (struct BSTreeNode * root , int space) {

	struct BSTreeNode * traverser = root;

	if(traverser == NULL) {
		return;
	}

	space += COUNT;

	TraverseBST(traverser->left , space);
	
	printf("\n");
	for(int i = COUNT; i < space; i++){
		printf(" ");
	}
	printf("%d\n" , root->key);
	
	TraverseBST(traverser->right , space);
	

}

void FreeBST(struct BSTreeNode * root) {

	if(root != NULL){
		FreeBST(root->right);
		FreeBST(root->left);
		free(root);
	}
}

bool SearchBST (struct BSTreeNode * root , int search_val) {

	if(root == NULL) {

		// ONCE A DEAD END IS HIT , ROOT POINTS TO NOTHING
		// (i.e NULL)

		return false;
	} else if (search_val < root->key) {
		return SearchBST(root->left , search_val);
	} else if (search_val > root->key ){
		 return SearchBST(root->right , search_val);
	} else {
		return true;	
	}
}

struct BSTreeNode * DeleteBST (struct BSTreeNode * root , int value) {


}