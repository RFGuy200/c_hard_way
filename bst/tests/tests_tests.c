#include "minunit.h"
#include <bst.h>

char *test_demo(){

	return NULL;
}

char *test_Node_create()
{
	int value = 5;
	BstNode *test = Create_node(value);
	mu_assert(test->value == 5, "Node value should be 5.");
	free(test);

	return NULL;
}

char *test_create_tree()
{
	int *array= (int[]){3, 5, 4, 2, 1};
	int len = 5;

	BstTree *my_tree = Create_tree(array, len);
	mu_assert(my_tree->root->value == 3 && my_tree->root->left->value == 2 &&\
		my_tree->root->right->value == 5 && my_tree->root->right->left->value == 4\
		&& my_tree->root->left->left->value == 1 && my_tree->number == 5\
		, "Tree is not correct.");

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	mu_run_test(test_Node_create);
	mu_run_test(test_create_tree);
	
	return NULL;
}

RUN_TESTS(all_tests);


