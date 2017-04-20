#include "minunit.h"
#include <list.h>

List *list = NULL;

char *test_create()
{
	list = List_create();
	mu_assert(list != NULL, "Failed to create list.");

	return NULL;
}

char *test_destroy()
{
	List_destroy(list);

	return NULL;
}

char *test_push()
{
	int var = 1;
	List_push(list, &var);
	mu_assert(list->last->data == &var && list->count == 1, "Data should be var after push.");
	printf("Value of list->last->data = %d\n", *(int*)list->last->data);

	return NULL;
}


char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


