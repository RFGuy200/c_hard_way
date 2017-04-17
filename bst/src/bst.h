#ifndef bst_h
#define bst_h

#include <stdlib.h>
#include <dbg.h>
#include <assert.h>

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
void Destroy_nodes(BstNode *node);

BstNode* Search_node(BstTree *tree, int value);
void Insert_node(BstTree *tree, int value);
void Remove_node(BstTree *tree, int value);
int Find(BstTree *tree, int value);
BstNode* find_delete_node(BstNode *root, int value);
BstNode* find_min(BstNode *root);
int Find_height(BstNode *root);
int Tree_height(BstTree *tree);
void Print_tree(BstTree *tree);
void Print_preorder(BstNode *root);
void Print_inorder(BstNode *root);
void Bst_check(BstNode *root);
void Bst_confirm(BstTree *tree);
#endif
