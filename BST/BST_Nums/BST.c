#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "BST.h"

#define COUNT 5

typedef struct BSTreeNode {
	int value;
	BSTree left;
	BSTree right;
	int height;
} BSTreeNode;

int max(int a , int b) {
	return (a > b) ? a : b;
}

int getBalanceFactor(BSTree root) {
	if(root == NULL) {
		return 0;
	} else {
		return (NodeHeight(root->left) - NodeHeight(root->right));
	}
}

BSTree RotateR(BSTree y) {
	assert(y != NULL);
	BSTree x = y->left;
	BSTree T2 = x->right;
	//Perform rotation
	x->right= y;
	y->left = T2;
	//Update heights
	y->height = max(NodeHeight(y->left) , NodeHeight(y->right)) + 1;
	x->height = max(NodeHeight(x->left) , NodeHeight(x->right)) + 1;
	// Return new root
	return x;
}

BSTree RotateL(BSTree x) {
	assert(x != NULL);
	BSTree y = x->right;
	BSTree T2 = y->left;
	//Perform rotation
	y->left = x;
	x->right = T2;
	//Update heights
	x->height = max(NodeHeight(x->left) , NodeHeight(x->right)) + 1;
	y->height = max(NodeHeight(y->left) , NodeHeight(y->right)) + 1;
	//Return new root;
	return y;
}

BSTree BSTreeNodeInsert (BSTree root , int value) {

	if(root == NULL) {
		return MakeNewNode(value);
	} else if(root->value < value) {
		root->left = BSTreeNodeInsert (root->left , value);
	} else if(root->value > value) {
		root->right = BSTreeNodeInsert (root->right , value);
	}

	root->height = 1 + max(NodeHeight(root->left) , NodeHeight(root->right));

	int balance_factor = getBalanceFactor(root);

	// Left-Left case
	if(balance_factor > 1 && value < root->left->value) {
		return RotateR(root);
	}
	// Right-Right case
	if(balance_factor < -1 && value > root->right->value) {
		return RotateL(root);
	}
	// Left-Right case
	if(balance_factor > 1 && value > root->left->value) {
		root->left = RotateL(root->left);
		return RotateR(root);
	}
	//Right-Left case
	if(balance_factor < -1 && value < root->right->value) {
		root->right = RotateR(root->right);
		return RotateL(root);
	}
	return root;
}

BSTree MakeNewNode (int value) {

	BSTree new_node = malloc(sizeof(BSTreeNode));
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1;
	return new_node;

}

int NodeHeight(BSTree root) {
	if(root == NULL) {
		return 0;
	} else {
		return root->height;
	}
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
