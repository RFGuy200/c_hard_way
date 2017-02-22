#include "minunit.h"
#include <darray.h>

static DArray *array = NULL;
static int __attribute__((unused)) *val1 = NULL;
static int __attribute__((unused)) *val2 = NULL;


char *test_create()
{
	array = DArray_create(sizeof(int), 100);
	mu_assert(array != NULL, "Failed to create new array.");
	mu_assert(array->end == 0, "new array end at the wrong spot.");
	mu_assert(array->max == 100, "new array max is wrong.");
	mu_assert(array->element_size == sizeof(int), "new array element size is wrong.");
	mu_assert(array->expand_rate == DEFAULT_EXPAND_RATE, "new array expand rate is wrong.");
	mu_assert(array->contents != NULL, "new array contents is wrong.");	

	return NULL;
}

char *test_destroy()
{
	DArray_destroy(array);

	return NULL;
}

char *test_create_new()
{
	val1 = DArray_new(array);
	mu_assert(val1 != NULL, "Failed to create new element.");
	*val1 = 10;

	val2 = DArray_new(array);
	mu_assert(val2 != NULL, "Failed to create new element.");
	*val2 = 20;

	return NULL;
}

char *test_set()
{
	DArray_set(array, 0, val1);
	mu_assert(array->contents[0] == val1, "Failed to set array element.");
	
	DArray_set(array, 1, val2);
	mu_assert(array->contents[1] == val2, "Failed to set array element.");

	return NULL;
}

char *test_expand_contract()
{
	int old_max = array->max;

	DArray_expand(array);
	mu_assert(array->max ==  old_max + (int) array->expand_rate,\
			 "Failed to expand to new array size during test.");

	DArray_contract(array);
	mu_assert(array->max ==  (int) array->expand_rate,\
			 "Failed to contract, max should stay at least expand_rate.");	

	DArray_contract(array);
	mu_assert(array->max ==  (int) array->expand_rate,\
			 "Failed to contract, max should stay at least expand_rate.");	
	return NULL;
}

char *test_remove()
{
	int *val_check =  DArray_remove(array, 0);
	mu_assert(val_check !=NULL, "val_check should not be NULL.");
	mu_assert(*val_check == *val1, "Error wrong value retrieved after remove.");
	mu_assert(DArray_get(array, 0) == NULL, "Error member 0 should be NULL.");
	free(val_check);

	val_check = DArray_remove(array, 1);
	mu_assert(*val_check == *val2, "Error wrong value retrieved after remove.");
	mu_assert(DArray_get(array, 1) == NULL, "Error member 1 should be NULL.");
	free(val_check);

	return NULL;
}

char *test_push_pop()
{
	int i = 0;

	for(i = 0; i < 1000; i++){
		int *val = DArray_new(array);
		*val = i * 333;
		DArray_push(array, val);
	}

	mu_assert(array->max == 1200, "Wrong array size after push.");

	for(i = 999; i >=0; i--){
		int *val = DArray_pop(array);
		mu_assert(val != NULL, "Should not get NULL after pop.");
		mu_assert(*val == i * 333, "Wrong value after pop.");
		DArray_free(val);
	}

	return NULL;
}



char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_create_new);
	mu_run_test(test_set);
	mu_run_test(test_remove);
	mu_run_test(test_expand_contract);
	mu_run_test(test_push_pop);
	mu_run_test(test_destroy);

	
	return NULL;
}

RUN_TESTS(all_tests);


