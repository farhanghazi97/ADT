#include <stdio.h>
#include <stdbool.h>

#include "BST.h"

int main(void) {

    BSTree Tree = NULL;
    char value[BUFSIZ];

    while(fgets(value , BUFSIZ , stdin) != NULL) {
        Tree = InsertBSTNode(Tree , value);
    }

    int TNodes = CountTotalNodes(Tree);
    printf("\nTotal nodes: %d\n" , TNodes);
    int LNodes = CountLeaveNodes(Tree);
    printf("Leaf nodes: %d\n" , LNodes);
    int INodes = CountInternalNodes(Tree);
    printf("Internal nodes: %d\n" , INodes);
    int Height = TreeHeight(Tree);
    printf("Tree height: %d\n" , Height);

    bool is_balanced = HeightBalanced(Tree);
    if(is_balanced) {
        printf("The tree is height balanced!\n");
    } else {
        printf("The tree is not height balanced!\n");
    }

    bool found = SearchString(Tree , "farhan");
    if(found) {
        printf("String exists within tree!\n");
    } else {
        printf("String not found!\n");
    }

    ShowBST(Tree , 0);
    FreeBST(Tree);
}
