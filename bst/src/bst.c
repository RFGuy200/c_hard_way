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

void Insert_node(BstTree *tree, int value)
{
		BstNode *temp = Create_node(value);
		check_mem(temp);

		BstNode *cur = tree->root;

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
error:
	return;

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
	BstNode *found = NULL;

	while(cur != NULL){
		if(cur->value == value){
			found = cur;
			break;	
		}else if(value > cur->value){
			cur = cur->right;
		}else{
			cur = cur->left;
		}
	}
	return found;
}

BstNode* find_min(BstNode *root)
{
	if(root->left == NULL){
		return root;
	}else if(root->left->left == NULL){
		BstNode *temp = root->left;
		root->left = NULL;
		return temp;
	}else{
		find_min(root->left);
	}
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
		}else if(root->right == NULL){
			temp = root;
			root = root->left;
			free(temp);
		}else if(root->left == NULL){
			temp = root;
			root = root->right;
			free(temp);
		}else{
			temp = root;
			root = find_min(root->right);
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

int Find_height(BstNode *root)
{
	if(root == NULL){
		return -1;
	}else{
		int lefth = Find_height(root->left);
		int righth = Find_height(root->right);

		if(lefth > righth)
			return lefth + 1;
		else{
			return righth + 1;
		}
	}
}

int Tree_height(BstTree *tree)
{
	int height = Find_height(tree->root);
	
	return height;
}

void Print_preorder(BstNode *root)
{
	if(root == NULL)
		return;
	printf("\n%d", root->value);
	Print_preorder(root->left);
	Print_preorder(root->right);
}


void Print_inorder(BstNode *root)
{
	if(root == NULL)
		return;
	Print_inorder(root->left);
	printf("\n%d", root->value);
	Print_inorder(root->right);
}


void Print_postorder(BstNode *root)
{
	if(root == NULL)
		return;
	Print_postorder(root->left);
	Print_postorder(root->right);
	printf("\n%d", root->value);
}

void Print_tree(BstTree *tree)
{
	Print_preorder(tree->root);
	Print_inorder(tree->root);
	Print_postorder(tree->root);
}

int find_min_check(BstNode *root)
{
	if(root->left == NULL){
		return root->value;
	}else{
		find_min_check(root->left);
	}
}

int find_max_check(BstNode *root)
{
	if(root->right == NULL){
		return root->value;
	}else{
		find_max_check(root->right);
	}
}

int  Bst_check(BstNode *root)
{
	int min = 1;
	int max = 1;
	int right_sub = 1;
	int left_sub = 1;

	if(root->right){
		min = find_min_check(root->right) > root->value;
	}

	if(root->left){
		max = find_max_check(root->left) < root->value;
	}

	if(root->right){
		right_sub = Bst_check(root->right);
	}

	if(root->left){
		left_sub = Bst_check(root->left);
	}

	if(min && max && right_sub && left_sub){
		return 1;
	}else{
		return 0;
	}
}

void Bst_confirm(BstTree *tree)
{
	Bst_check(tree->root);
}

int Find_succ(BstTree *tree, int value)
{
	BstNode* cur = Search_node(tree, value);
	check(cur != NULL, "Value not found.");

	if(cur->right){
		return find_min_check(cur->right); 
	}
	
	BstNode *temp = tree->root;
	BstNode *succ = tree->root;

	while(temp != cur){
		if(cur->value < temp->value){
			succ = temp;
			temp = temp->left;
		}else{
			temp = temp->right;
		}
	}
	return succ->value;	

error:
	exit(EXIT_FAILURE);
}

int Find_pred(BstTree *tree, int value)
{
	BstNode *cur = Search_node(tree, value);

	check(cur != NULL, "Value not found.");

	if(cur->left){
		return find_max_check(cur->left);
	}

	BstNode *temp = tree->root;
	BstNode *succ = tree->root;

	while(temp != cur){
		if(cur->value > temp->value){
			succ = temp;
			temp = temp->right;
		}else{
			temp = temp->left;
		}
	}
	return succ->value;

error:
	exit(EXIT_FAILURE);
}


