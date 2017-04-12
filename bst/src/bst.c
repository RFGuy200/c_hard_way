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
	int i = 0;	

	check(array != NULL && len > 0, "To use BST need valid array with length > 0.");
	BstTree *tree = calloc(1, sizeof(BstTree));
	tree->number = 0;

	BstNode *root = Create_node(0); 
	
	for(i = 0 ;i < len; i++){
		if(i == 0){
			 root->value = array[i];
			tree->number++;
			continue;
		}

		BstNode *temp = Create_node(array[i]);
		BstNode *cur = root;
		
		while(1){
			if(cur->value >= temp->value && cur->left == NULL){
					cur->left = temp;
					tree->number++;
					break;
			}else if(cur->value < temp->value && cur->right == NULL){
					cur->right = temp;
					tree->number++;
					break;
			}else if(cur->value < temp->value && cur->right){
				cur = cur->right;
				continue;
			}else{
				cur = cur->left;
				continue;
			}
		}
	}
	
	tree->root = root;
	return tree;
error:
	return NULL;

}

void Destroy_nodes(BstNode *node)
{
	if(node == NULL)
		return;
	
	if(node->left != NULL){
		 Destroy_nodes(node->left);
	}
	
	if(node->right != NULL){
		Destroy_nodes(node->right);
	}
		free(node);
}


	

void Destroy_tree(BstTree *tree)
{
	assert(tree != NULL && "Tree pointer should not be NULL.");

	Destroy_nodes(tree->root);
	free(tree);
}

BstNode* Search_node(BstTree *tree, int value)
{
	assert(tree != NULL && "Can't search empty tree.");

	BstNode *cur = tree->root;

	while(cur != NULL){
		if(cur->value == value){
			break;	
		}else if(value > cur->value){
			cur = cur->right;
		}else{
			cur = cur->left;
		}
	}
	return cur;
}
			


void Remove_node(BstTree *tree, int value)
{
	Search_node(tree, value);
}



