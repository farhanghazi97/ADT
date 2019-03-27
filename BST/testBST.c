#include <stdio.h>
#include "BST.h"

int main(void) {

	BSTree Tree = NULL;

	int value;
	while(scanf("%d" , &value) == 1){
		Tree = BSTreeNodeInsert(Tree , value);
	}

	int Tnodes = CountTotalNodes(Tree);
	printf("Total number of nodes: %d\n" , Tnodes);

	int INodes = CountInternalNodes(Tree);
	printf("Total number of internal nodes: %d\n" , INodes);

	int LNodes = CountLeaves(Tree);
	printf("Total leaves: %d\n" , LNodes);

	int height = TreeHeight(Tree);
	printf("The height of the tree is: %d\n" , height);

	bool is_balanced = HeightBalanced(Tree);
	if(is_balanced) {
		printf("The given tree is balanced\n\n");
	} else {
		printf("The given tree is not balanced\n\n");
	}

	printf("Infix order: "); InFixOrder(Tree);   printf("\n\n");
	printf("Prefix order: "); PrefixOrder(Tree);  printf("\n\n");
	printf("Postfix order: "); PostFixOrder(Tree); printf("\n\n");

	TraverseBST(Tree , 0);
	FreeBSTree (Tree);

}
