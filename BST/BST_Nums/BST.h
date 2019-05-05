#include <stdbool.h>

typedef struct BSTreeNode * BSTree;

BSTree BSTreeNodeInsert (BSTree root , int value);
BSTree MakeNewNode 		(int value);
BSTree RotateL          (BSTree x);
BSTree RotateR          (BSTree y);

void TraverseBST  (BSTree root , int space);
void InFixOrder   (BSTree root);
void PrefixOrder  (BSTree root);
void PostFixOrder (BSTree root);
void FreeBSTree   (BSTree root);

int CountTotalNodes     (BSTree root);
int CountLeaves    		(BSTree root);
int CountInternalNodes	(BSTree root);
int TreeHeight     		(BSTree root);
int max                 (int a , int b);
int getBalanceFactor    (BSTree root);
int NodeHeight          (BSTree root);

bool HeightBalanced (BSTree root);
