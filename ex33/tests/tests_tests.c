#include "minunit.h"
#include <list.h>
#include <algos.h>

List *list = NULL;
char *test1 = "test1";
char *test2 = "test2";
char *test3 = "test3";
char *test4 = "test4";
char *test5 = "test5";

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
	mu_assert(list->last->value == test1 &&\
		list->count == 1, "Failed to push");			

	List_push(list, test2);
	mu_assert(list->last->value == test2 &&\
		list->count == 2, "Failed to push");	
	
	List_push(list, test3);
	mu_assert(list->last->value == test3  &&\
		list->count == 3, "Failed to push");
	
	return NULL;
}	

char *test_pop()
{
	List_pop(list);
	mu_assert(list->last->value == test2 &&\
		list->count == 2, "Failed to pop from the list.");

	List_pop(list);
	mu_assert(list->last->value == test1 &&\
		list->count == 1, "Failed to pop from the list.");

	List_pop(list);
	mu_assert(list->count == 0, "Failed to pop from the list.");

	return NULL;
}

char *test_unshift()
{
	List_unshift(list, test1);
	mu_assert(list->first->value == test1 &&\
		list->count == 1, "Failed to unshift the list.");
		
	List_unshift(list, test2);
	mu_assert(list->first->value == test2 &&\
		list->count == 2, "Failed to unshift the list.");

	List_unshift(list, test3);
	mu_assert(list->first->value == test3 &&\
		list->count == 3, "Failed to unshift the list.");

	return NULL;
}

char *test_shift()
{
	List_shift(list);
	mu_assert(list->first->value == test2 &&\
		list->count == 2, "Failed to shift the list.");

	List_shift(list);
	mu_assert(list->first->value == test1 &&\
		list->count == 1, "Failed to shift the list.");

	List_shift(list);
	mu_assert(list->count == 0, "Failed to shift the list.");

	return NULL;
}

char *test_bubble_sort()
{
	List_push(list, test5);
	List_push(list, test1);
	List_push(list, test4);
	List_push(list, test2);
	List_push(list, test3);

	bubble_sort(list);

	mu_assert(list->first->value == test1 && list->last->value == test5,\
		 "Failed to bubble sort the list.");

	return NULL;
}

char *test_merge()
{
	List_push(list, test5);
	List_push(list, test1);
	List_push(list, test4);
	List_push(list, test2);
	List_push(list, test3);

	merge_sort(list);	

	return NULL;
}




char *all_tests()
{

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_pop);
	mu_run_test(test_unshift);
	mu_run_test(test_shift);
	mu_run_test(test_destroy);
	mu_run_test(test_create);
	mu_run_test(test_bubble_sort);
	mu_run_test(test_destroy);
	mu_run_test(test_create);
	mu_run_test(test_merge);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


