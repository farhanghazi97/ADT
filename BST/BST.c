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


struct BSTreeNode * CreateNode (int value) {

	struct BSTreeNode * new_node = malloc(sizeof(struct BSTreeNode *));
	new_node->key = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct BSTreeNode * InsertBSTNode(struct BSTreeNode * root , int key) {

	if(root == NULL){
		struct BSTreeNode * new_node = CreateNode(key);
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
		return false;
	} else if (search_val < root->key) {
		return SearchBST(root->left , search_val);
	} else if (search_val > root->key ){
		 return SearchBST(root->right , search_val);
	} else {
		return true;	
	}
}

struct BSTreeNode * FindMaxBST (struct BSTreeNode * root) {

	struct BSTreeNode * curr = root;
	while(curr->right != NULL) {
		curr = curr->right;
	}
	return curr;
}

struct BSTreeNode * FindMinBST (struct BSTreeNode * root) {

	struct BSTreeNode * current = root;
	while(current->left != NULL) {
		current = current->left;
	}
	return current;
}

struct BSTreeNode * DeleteBSTNode (struct BSTreeNode * root , int value) {

	if (root == NULL) return root;

	//DELETE NODE WITH ONLY ONE CHILD
	if (value < root->key) {
		root->left = DeleteBSTNode (root->left , value);
	} else if (value > root->key) {
		root->right = DeleteBSTNode (root->right , value);
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
	
		//DELETE NODE WITH TWO CHILDREN
		struct BSTreeNode * temp = FindMinBST(root->right);
		root->key = temp->key;
		root->right - DeleteBSTNode(root->right , temp->key);
	}
	
	return root;

}

void Action () {
 	
	printf("\n0. Exit program\n");
	printf("1. Search for a term in BST\n");
	printf("2. Delete a term from the BST\n");
	printf("3. Find maximal element within BST\n");
	printf("4. Find mininal element within BST\n");
}

