#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 5 

struct BSTreeNode {
	int key;
	struct BSTreeNode * left;
	struct BSTreeNode * right;
};

struct BSTreeNode * create_node    (int value);
struct BSTreeNode * CreateBST	   (struct BSTreeNode * root);
struct BSTreeNode * InsertBSTNode  (struct BSTreeNode * root , int key);
struct BSTreeNode * MinValNode 	   (struct BSTreeNode * root);
bool   SearchBST 		   (struct BSTreeNode * root , int search_val);
int    FindMaxBST		   (struct BSTreeNode * root);
void   TraverseBST  		   (struct BSTreeNode * root , int space);
void   FreeBST      		   (struct BSTreeNode * root);
void   Action	    		   ();


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
	while(input != EOF) {
		scanf("%d" , &input);
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

struct BSTreeNode * MinValNode (struct BSTreeNode * root) {

	struct BSTreeNode * current = root;
	while(current->left != NULL) {
		current = current->left;
	}
	return current;
}

struct BSTreeNode * DeleteBST (struct BSTreeNode * root , int value) {

	if (root == NULL) return root;

	if (value < root->key) {
		root->left = DeleteBST (root->left , value);
	} else if (value > root->key) {
		root->right = DeleteBST (root->right , value);
	} else {
		if (root->left == NULL) {
			struct BSTreeNode * temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct BSTreeNode * temp = root->left;
			free(root);
			return temp;
		}
	}

	struct BSTreeNode * temp = MinValNode (root->right);
	printf("VALUE : %d\n" , temp->key); 

	//root->key = temp->key;
	//root->right = DeleteBST(root->right , temp->key);
	
	return root;

}

void Action () {
 	
	printf("\n0. Exit program\n");
	printf("1. Search for a term in BST\n");
	printf("2. Delete a term from the BST\n");
	printf("3. Find maximal element within BST\n");
}

int FindMaxBST (struct BSTreeNode * root) {

	struct BSTreeNode * curr = root;
	while(curr->right != NULL) {
		curr = curr->right;
	}
	return(curr->key);
}
