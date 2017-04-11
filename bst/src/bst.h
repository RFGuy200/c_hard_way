#ifndef bst_h
#define bst_h

#include <stdlib.h>
#include <dbg.h>

typedef struct BstNode{
	int value;
	struct BstNode *left;
	struct BstNode *right;
}BstNode;

typedef struct BstTree{
	BstNode *root;
	int number;
}BstTree;

BstNode* Create_node(int value);
BstTree* Create_tree(int *array, int len);
void Destroy_tree(BstTree *tree);

void Insert_node(BstTree *tree, int value);
int Remove_node(BstTree *tree, int value);
int Find(BstTree *tree, int value);

#endif
