#include "minunit.h"
#include <libda/darray.h>

static Darray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;

char *test_demo(){

	return NULL;
}

char test_create()
{
	array = Darray_create(sizeof(int), 100);
	mu_assert(array != NULL, "Failed to create darray");
	mu_assert(array->contents != NULL, "Contents are wrong in darray");
	mu_assert(array->end == 0, "darray end isn't at the right spot");
	mu_assert(array->element_size == sizeof(int), "element size is wrong");
	mu_assert(array->max == 100, "array max is wrong");

	return NULL;
}
	

char *all_tests(){

	mu_suite_start();



	mu_run_test(test_demo);
	mu_run_test(test_create);
	
	return NULL;
}

RUN_TESTS(all_tests);


