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

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	mu_run_test(test_Node_create);
	
	return NULL;
}

RUN_TESTS(all_tests);


