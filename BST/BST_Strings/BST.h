#include <stdbool.h>

typedef struct BSTreeNode * BSTree;

BSTree NewBSTNode    (char * value);
BSTree InsertBSTNode (BSTree root , char * value);

void FreeBST (BSTree root);
void ShowBST (BSTree root , int space);

int  CountTotalNodes    (BSTree root);
int  CountLeaveNodes    (BSTree root);
int  CountInternalNodes (BSTree root);
int  TreeHeight         (BSTree root);

bool HeightBalanced (BSTree root);
bool SearchString   (BSTree root , char * string);
