#include "minunit.h"
#include <test.h>

bstring my_str = NULL;
bstring my_str_1 = NULL;

char *test_bcreate()
{
	my_str = bfromcstr("this is a test str\0");

	return NULL;
}

char *test_bdestroy()
{
	int i = bdestroy(my_str);
	mu_assert(i == 0, "Error destroying bstring.");

	i = bdestroy(my_str_1);
	mu_assert(i == 0, "Error destroying bstring.");

	return NULL;
}

char *test_blk2bstr()
{
	my_str_1 = blk2bstr(my_str->data, 1);

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_bcreate);
	mu_run_test(test_blk2bstr);
	mu_run_test(test_bdestroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


