#include "minunit.h"
#include <libda/darray.h>

static Darray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;

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

char test_clear()
{
	Darray_clear(array);

	return NULL;
}

char test_expand_contract()
{
	int old_max = array->max;
	Darray_expand(array);
	mu_assert((unsigned int) array->max == old_max + array->expand_rate, "\
		Wrong size after expand");
	Darray_contract(array);
	mu_assert((unsigned int) array->max == array->expand_rate + 1, "Should stay at least at\
		default expand rate at least");
	Darray_contract(array);
	mu_assert((unsigned int) array->max == array->expand_rate + 1, "Should stay at least at\
		default expand rate at least");

	return NULL;
}
	

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_expand_contract);
	mu_run_test(test_clear);	
	return NULL;
}

RUN_TESTS(all_tests);


