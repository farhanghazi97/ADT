#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 5 

struct BSTreeNode {
	int    key;
	struct BSTreeNode * left;
	struct BSTreeNode * right;
};

struct BSTreeNode * CreateNode     (int value);
struct BSTreeNode * CreateBST	   (struct BSTreeNode * root);
struct BSTreeNode * InsertBSTNode  (struct BSTreeNode * root , int key);
struct BSTreeNode * FindMaxBST	   (struct BSTreeNode * root);
struct BSTreeNode * FindMinBST     (struct BSTreeNode * root);
struct BSTreeNode * DeleteBSTNode  (struct BSTreeNode * root , int value); 
bool   				SearchBST 	   (struct BSTreeNode * root , int search_val);
void   				TraverseBST    (struct BSTreeNode * root , int space);
void   				FreeBST        (struct BSTreeNode * root);
void   				Action	       ();