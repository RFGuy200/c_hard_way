#include "minunit.h"
#include <test.h>

bstring my_str = NULL;
bstring my_str_1 = NULL;
bstring my_str_2 = NULL;

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

	i = bdestroy(my_str_2);
	mu_assert(i == 0, "Error destroying bstring.");



	return NULL;
}

char *test_blk2bstr()
{
	my_str_1 = blk2bstr(my_str->data, 1);

	return NULL;
}

char *test_bstrcpy()
{
	my_str_2 = bstrcpy(my_str_1);

	return NULL;
}


char *test_bassign()
{
	int i = bassign(my_str_2, my_str);
	mu_assert(i == 0, "Error assigning bstring.");

	return NULL;
}

char *test_bassigncstr()
{
	int i = bassigncstr(my_str_2, "another tests\0");
	mu_assert(i == 0, "Error assigning c string to bstring.");

	return NULL;
}

char *test_bassignblk()
{
	int i = bassignblk(my_str_2, "yet another test\0", 4);
	mu_assert(i == 0, "Error assigning mem block to bstring.");

	return NULL;
}

char *test_bconcat()
{
	int i = bconcat(my_str_2, my_str);
	mu_assert(i == 0, "Error concatinating bstrings.");

	return NULL;
}

char *test_bstrcmp()
{
	bassigncstr(my_str, "Alexander Kornishev\0");
	bassigncstr(my_str_1, "Blexander Kornishev\0");

	int i = bstrcmp(my_str, my_str_1);
	mu_assert(i < 0, "bstrcmp test failed.");

	return NULL;
}

char *test_biseq()
{
	bassigncstr(my_str, "Alexander Kornishev\0");
	bassigncstr(my_str_1, "Alexander Kornishev\0");

	int i = bstrcmp(my_str, my_str_1);	
	mu_assert(i == 0, "bstrcmp should return 0.");

	i = biseq(my_str, my_str_1);
	mu_assert(i == 1, "biseq should return 1.");

	return NULL;
}

char *test_binstr()
{
	bassigncstr(my_str, "Alexander Kornishev\0");
	bassigncstr(my_str_1, "Alex\0");

	int i = binstr(my_str, 0, my_str_1);
	mu_assert(i == 0, "binstr should return 0 position.");

	return NULL;
}

char *test_bfindreplace()
{
	bassigncstr(my_str, "Alexander Kornishev Alexander Kornishev\0");
	bassigncstr(my_str_1, "Alexander\0");
	bassigncstr(my_str_2, "Inesa\0");

	int i = bfindreplace(my_str, my_str_1, my_str_2, 0);
	mu_assert(i == 0, "bfindreplace failed.");

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_bcreate);
	mu_run_test(test_blk2bstr);
	mu_run_test(test_bstrcpy);
	mu_run_test(test_bassign);
	mu_run_test(test_bassigncstr);
	mu_run_test(test_bassignblk);
	mu_run_test(test_bconcat);
	mu_run_test(test_bstrcmp);
	mu_run_test(test_biseq);
	mu_run_test(test_binstr);
	mu_run_test(test_bfindreplace);
	mu_run_test(test_bdestroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


