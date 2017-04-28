#include "minunit.h"
#include <hashmap.h>
#include <assert.h>
#include <bstrlib.h>

Hashmap *map = NULL;
static int traverse_called = 0;
struct tagbstring test1 = bsStatic("test data 1");
struct tagbstring test2 = bsStatic("test data 2");
struct tagbstring test3 = bsStatic("test data 3");

struct tagbstring expect1 = bsStatic("THE VALUE 1");
struct tagbstring expect2 = bsStatic("THE VALUE 2");
struct tagbstring expect3 = bsStatic("THE VALUE 3");

static int traverse_good_cb(HashmapNode *node)
{
	debug("KEY:%s", bdata((bstring)node->key));
	traverse_called++;
	return 0;
}


char *test_demo(){

	return NULL;
}

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	
	return NULL;
}

RUN_TESTS(all_tests);


