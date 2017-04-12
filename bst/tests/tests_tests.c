#include "minunit.h"
#include <bst.h>

BstTree *my_tree;

char *test_create_tree()
{
	int *array= (int[]){3, 5, 4, 2, 1};
	int len = 5;

	my_tree = Create_tree(array, len);
	mu_assert(my_tree->root->value == 3 && my_tree->root->left->value == 2 &&\
		my_tree->root->right->value == 5 && my_tree->root->right->left->value == 4\
		&& my_tree->root->left->left->value == 1 && my_tree->number == 5\
		, "Tree is not correct.");

	return NULL;
}

char *test_destroy_tree()
{
	Destroy_tree(my_tree);

	return NULL;
}

char *test_search_node()
{
	BstNode *number = Search_node(my_tree, 5);

	mu_assert(number->value == 5, "Search should find number 5 in the tree.");

	number = Search_node(my_tree, 0);
	mu_assert(number == NULL, "Search should return NULL.");

	return NULL;
}
	

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create_tree);
	mu_run_test(test_search_node);
	mu_run_test(test_destroy_tree);
	
	return NULL;
}

RUN_TESTS(all_tests);


