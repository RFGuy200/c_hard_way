#include "minunit.h"
#include <bstrlib.h>

bstring my_str = NULL;

char *test_bstr_create()
{
	my_str = bfromcstr("this is a test str\0");

	return NULL;
}

char *test_demo(){

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	mu_run_test(test_bstr_create);
	
	return NULL;
}

RUN_TESTS(all_tests);


