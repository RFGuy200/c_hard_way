#include "minunit.h"
#include <list.h>

List *list = NULL;
int *int_array = (int []){1, 3, 5, 7, 9, 11};

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
	List_push(list, &int_array[0]);
	mu_assert(list->last->data == &int_array[0] && list->count == 1, "Data should be var after push.");
	
	List_push(list, &int_array[1]);
	mu_assert(list->last->data == &int_array[1] && list->count == 2, "Data should be var after 2nd push.");


	List_push(list, &int_array[2]);
	mu_assert(list->last->data == &int_array[2] && list->count == 3, "Data should be var after 3nd push.");


	List_push(list, &int_array[3]);
	mu_assert(list->last->data == &int_array[3] && list->count == 4, "Data should be var after 4nd push.");


	List_push(list, &int_array[4]);
	mu_assert(list->last->data == &int_array[4] && list->count == 5, "Data should be var after 5nd push.");


	List_push(list, &int_array[5]);
	mu_assert(list->last->data == &int_array[5] && list->count == 6, "Data should be var after 6nd push.");

	return NULL;
}

char *test_reverse()
{
	List_reverse(list);
	mu_assert(list->first->data == &int_array[5] &&\
		list->last->data == &int_array[0], "List reverse failed.");

	return NULL;
}


char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_reverse);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


