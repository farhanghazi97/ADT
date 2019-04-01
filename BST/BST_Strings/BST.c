#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "BST.h"
#define COUNT 5

typedef struct BSTreeNode {
    char * string;
    BSTree left;
    BSTree right;
} BSTreeNode;

BSTree NewBSTNode (char * value) {
    BSTree new_node = malloc(sizeof(BSTreeNode));
    if(new_node == NULL) printf("Could not allocate memory for new node\n");
    new_node->string = malloc(strlen(value) * sizeof(char));
    strncpy(new_node->string , value , strlen(value + 1));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BSTree InsertBSTNode(BSTree root , char * value) {
    if(root == NULL) {
        return NewBSTNode(value);
    } else if(strcmp(root->string , value) < 0) {
        root->left = InsertBSTNode(root->left , value);
    } else if(strcmp(root->string , value) > 0) {
        root->right = InsertBSTNode(root->right , value);
    }
}

bool HeightBalanced (BSTree root) {
    if(root == NULL) {
        return true;
    } else {
        int LHeight = TreeHeight(root->left);
        int RHeight = TreeHeight(root->right);
        if(abs(LHeight - RHeight) <= 1 &&
            HeightBalanced(root->left) &&
            HeightBalanced(root->right)) {
                return true;
            }
    }
    return false;
}

bool SearchString (BSTree root , char * string) {
    if(root == NULL) {
        return false;
    } else if(strcmp(root->string , string) == 0) {
        return true;
    } else if(strcmp(root->string , string) < 0) {
        return SearchString(root->left , string);
    } else {
        return SearchString(root->right , string);
    }
}

void FreeBST(BSTree root) {
    if(root != NULL) {
        FreeBST(root->left);
        FreeBST(root->right);
        free(root->string);
        free(root);
    }
}

void ShowBST (BSTree root , int space) {
    BSTree curr = root;
    if(curr == NULL) {
        return;
    }
    space += COUNT;
    ShowBST(curr->left , space);
    printf("\n");
    for(int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%s\n" , root->string);
    ShowBST(root->right , space);
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

int CountTotalNodes (BSTree root) {
    if(root == NULL) {
        return 0;
    } else {
        return (1 + CountTotalNodes(root->left) + CountTotalNodes(root->right));
    }
}

int CountLeaveNodes (BSTree root) {
    if(root == NULL) {
        return 0;
    } else if(root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return CountLeaveNodes(root->left) + CountLeaveNodes(root->right);
    }
}

int CountInternalNodes (BSTree root) {
    return (CountTotalNodes(root) - CountLeaveNodes(root));
}
