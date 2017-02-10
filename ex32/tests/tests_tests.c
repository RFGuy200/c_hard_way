#include "minunit.h"
#include <list.h>
#include <string.h>

List *list = NULL;
char *test1 = "test1";
char *test2 = "test2";
char *test3 = "test3";

char *test_create()
{

	list = List_create();
	mu_assert( list != NULL, "Failed to create list.");

	return NULL;
}

char *test_destroy()
{

	List_destroy(list);

	return NULL;
}

char *test_push()
{
	List_push(list, test1);
	mu_assert(strcmp(list->last->value, "test1") == 0 &&\
		list->count == 1, "Failed to push");			

	List_push(list, test2);
	mu_assert(strcmp(list->last->value, "test2")  == 0 &&\
		list->count == 2, "Failed to push");	
	
	List_push(list, test3);
	mu_assert(strcmp(list->last->value, "test3") == 0  &&\
		list->count == 3, "Failed to push");
	
	return NULL;
}	



char *all_tests()
{

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


