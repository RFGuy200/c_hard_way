#include "minunit.h"
#include <test.h>
#include <string.h>

bstring my_str = NULL;
bstring my_str_1 = NULL;
bstring my_str_2 = NULL;
struct bstrList *my_list = NULL;
bstring fmt_str = NULL;


char *test_bfromcstr()
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

	i = bdestroy(fmt_str);
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

char *test_bsplit()
{
	bassigncstr(my_str, "Alexander Korishev\0");

	my_list =  bsplit(my_str, ' ');
	

	return NULL;
}

char *test_bstrList_destroy()
{
	int i = bstrListDestroy(my_list);
	mu_assert(i == 0, "failed to destroy bstrList.");

	return NULL;
}
	
char *test_bformat()
{
	fmt_str = bformat("first name: %s, last name: %s \0", "Alexander", "Kornishev");

	return NULL;
}

char *test_blength()
{
	bassigncstr(my_str, "Alexander\0");
	mu_assert(blength(my_str) == 9, "bstring length should be 10.");

	return NULL;
}

char *test_bdata()
{
	char *data = bdata(my_str);
	mu_assert(strcmp(data,"Alexander\0") == 0, "data should be identical.");

	return NULL;
}

char *test_bchar()
{
	char c = bchar(my_str, 0);
	mu_assert(c == 'A', "bchar should return 'A'.");

	return NULL;
}

char *test_bstr2cstr()
{
	bassigncstr(my_str_1, "Alexander\0");
	bconcat(my_str, my_str_1);

	char *c = bstr2cstr(my_str,' ' );
	mu_assert(strcmp(c, "AlexanderAlexander") == 0,\
			 "bstrcstr should return string");

	return NULL;
}

char *test_bsetstr()
{
	bassigncstr(my_str, "Alexander");
	bassigncstr(my_str_1, "Kornishev");

	bsetstr(my_str, blength(my_str) + 1, my_str_1, ' ');
	char *data = bdata(my_str);
	mu_assert(strcmp(data, "Alexander Kornishev") == 0,\
			"my_str should be Alexander Kornishev after bsetstr.");

	return NULL;
}

	

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_bfromcstr);
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
	mu_run_test(test_bsplit);
	mu_run_test(test_bstrList_destroy);
	mu_run_test(test_bformat);
	mu_run_test(test_blength);
	mu_run_test(test_bdata);
	mu_run_test(test_bchar);
	mu_run_test(test_bstr2cstr);
	mu_run_test(test_bsetstr);
	mu_run_test(test_bdestroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


