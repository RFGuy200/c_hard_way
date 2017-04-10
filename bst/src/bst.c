#include <bst.h>

BstNode* Create_node(int value)
{
	BstNode *new = calloc(1, sizeof(BstNode));
	check_mem(new);

	new->value = value;
	new->left = NULL;
	new->right = NULL;

	return new;	

error:
	return NULL;
}

BstTree* Create_tree(int *array, int len)
{
	check(array != NULL && len > 0, "To use BST need valid array with length > 0.");
	BstTree *tree = calloc(1, sizeof(BstTree));

	BstNode *root = Create_node(0);  


	return tree;
error:
	return NULL;

}
