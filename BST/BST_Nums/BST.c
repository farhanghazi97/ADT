#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BST.h"

#define COUNT 5

typedef struct BSTreeNode {
	int value;
	BSTree left;
	BSTree right;
} BSTreeNode;

BSTree BSTreeNodeInsert (BSTree root , int value) {

	if(root == NULL) {
		return MakeNewNode(value);
	} else if(root->value < value) {
		root->left = BSTreeNodeInsert (root->left , value);
	} else if(root->value > value) {
		root->right = BSTreeNodeInsert (root->right , value);
	}
	return root;
}

BSTree MakeNewNode (int value) {

	BSTree new_node = malloc(sizeof(BSTreeNode));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;

}

int CountTotalNodes (BSTree root) {

	if(root == NULL) {
		return 0;
	} else {
		return (1 + CountTotalNodes(root->left) + CountTotalNodes(root->right));
	}
}

int CountLeaves (BSTree root) {

	if(root == NULL) {
		return 0;
	} else if(root->right == NULL && root->left == NULL) {
		return 1;
	} else {
		return CountLeaves(root->left) + CountLeaves(root->right);
	}

}

int CountInternalNodes (BSTree root) {
	return CountTotalNodes(root) - CountLeaves(root);
}

int TreeHeight (BSTree root) {

	if(root == NULL) {
		return 0;
	} else {
		int LHeight = TreeHeight(root->left);
		int RHeight = TreeHeight(root->right);

		if(LHeight > RHeight) {
			return (LHeight + 1);
		} else {
			return (RHeight + 1);
		}
	}

}

void TraverseBST (BSTree root , int space) {

	BSTree traverser = root;
	if(traverser == NULL) {
		return;
	}

	space += COUNT;
	TraverseBST(traverser->left , space);

	printf("\n");
	for(int i = COUNT; i < space; i++) {
		printf(" ");
	}
	printf("%d\n" , root->value);

	TraverseBST(traverser->right , space);
}

void FreeBSTree (BSTree root) {
	if(root != NULL) {
		FreeBSTree(root->left);
		FreeBSTree(root->right);
		free(root);
	}
}

bool HeightBalanced (BSTree root) {
	if(root == NULL) {
		return true;
	} else {
		int LHeight = TreeHeight(root->left);
		int RHeight = TreeHeight(root->right);
		if(abs(LHeight-RHeight) <= 1 &&
			HeightBalanced(root->left) &&
			HeightBalanced(root->right)) {
			return true;
		}
		return false;
	}
}

void InFixOrder   (BSTree root) {

	if(root == NULL) return;

	InFixOrder(root->left);
	printf("%d " , root->value);
	InFixOrder(root->right);

}

void PrefixOrder  (BSTree root) {

	if(root == NULL) return;

	InFixOrder(root->left);
	InFixOrder(root->right);
	printf("%d " , root->value);

}

void PostFixOrder (BSTree root) {

	if(root == NULL) return;

	printf("%d " , root->value);
	InFixOrder(root->left);
	InFixOrder(root->right);

}
