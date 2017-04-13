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

BstNode* find_min(BstNode *root)
{
	BstNode *min = NULL;

	return min;
}

BstNode* find_delete_node(BstNode *root, int value)
{
	BstNode *temp = NULL;
	
	if(root == NULL)
		return NULL;
	if(value > root->value){
		 root->right = find_delete_node(root->right, value);
	}else if(value <root->value){
		root->left = find_delete_node(root->left, value);
	}else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left){
			temp = root;
			root = root->left;
			free(temp);
		}else if(root->right){
			temp = root;
			root = root->right;
			free(temp);
		}else{
			temp = root;
			root = find_min(root);
			root->left = temp->left;
			root->right = temp->right;
			free(temp);
		}
	}

	return root;
}

	

void Remove_node(BstTree *tree, int value)
{
	find_delete_node(tree->root, value);
		
}




