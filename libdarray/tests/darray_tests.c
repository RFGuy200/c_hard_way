#include "minunit.h"

char *test_demo(){

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	
	return NULL;
}

RUN_TESTS(all_tests);


