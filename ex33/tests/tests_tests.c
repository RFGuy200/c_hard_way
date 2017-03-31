#include "minunit.h"
#include <list.h>
#include <algos.h>
#include <time.h>

List *list = NULL;
char *test1 = "test1";
char *test2 = "test2";
char *test3 = "test3";
char *test4 = "test4";
char *test5 = "test5";
char *test6 = "test6";
char *test7 = "test7";
char *test8 = "test8";
char *test9 = "test9";
clock_t start_t, end_t, total_t;
int i = 0;

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
	start_t = clock();
	for(i = 0; i < 100; i++){
		List_push(list, test5);
		List_push(list, test1);
		List_push(list, test4);
		List_push(list, test2);
		List_push(list, test3);
		List_push(list, test6);
		List_push(list, test9);
		List_push(list, test8);
		List_push(list, test7);
		bubble_sort(list);
	}
	end_t = clock();
	total_t =(end_t-start_t);
	printf("Bubble sort total run time %d times: %ld\n", i, total_t);

	mu_assert(list->first->value == test1 && list->last->value == test9,\
		 "Failed to bubble sort the list.");

	return NULL;
}

char *test_merge()
{
	start_t = clock();
	for(i = 0; i < 100; i++){
		List_push(list, test5);
		List_push(list, test1);
		List_push(list, test4);
		List_push(list, test2);
		List_push(list, test3);
		List_push(list, test6);
		List_push(list, test9);
		List_push(list, test8);
		List_push(list, test7);
		merge_sort(list);	
	}
	end_t = clock();
	total_t =(end_t-start_t);
	printf("Merge sort total run time %d times: %ld\n", i, total_t);

	mu_assert(list->first->value == test1 && list->last->value == test9,\
		 "Failed to merge sort the list.");

	return NULL;
}

char *test_upside()
{
	start_t = clock();
	for(i = 0; i < 100; i++){
		List_push(list, test5);
		List_push(list, test1);
		List_push(list, test4);
		List_push(list, test2);
		List_push(list, test3);
		List_push(list, test6);
		List_push(list, test9);
		List_push(list, test8);
		List_push(list, test7);
		upside_merge(list);
	}
	end_t = clock();
	total_t =(end_t-start_t);
	printf("Bottom-up merge sort total run time %d times: %ld\n", i, total_t);

	mu_assert(list->first->value == test1 && list->last->value == test9,\
		 "Failed to bottom-up merge sort the list.");
	
	return NULL;
}

void print_list(List *list)
{
	ListNode *cur_list = list->first;

	printf("Here is the last iteration after sorting:\n");
	for(i = 0; i < list->count; i++){
		printf("%s\n", cur_list->value);
		cur_list = cur_list->next;
	}
	printf("\n");
}

char *test_insert()
{
	start_t = clock();
	for(i = 0; i < 100; i++){
		List_push(list, test5);
		List_push(list, test1);
		List_push(list, test4);
		List_push(list, test2);
		List_push(list, test3);
		List_push(list, test6);
		List_push(list, test9);
		List_push(list, test8);
		List_push(list, test7);
		insert_sort(list);
	}
	end_t = clock();
	total_t =(end_t-start_t);
	printf("Insert sort total run time %d times: %ld\n", i, total_t);

	mu_assert(list->first->value == test1 && list->last->value == test9,\
		 "Failed to Insert sort the list.");
	
	return NULL;
}

char *test_shell()
{
		start_t = clock();
	int values[] = {1,9,2,8,3,7,4,6,5};
	int *array = malloc(sizeof(values));

	memcpy(array, values, sizeof(values));

	shell_sort (array, sizeof(values)/sizeof(values[0]));

	end_t = clock();
	total_t =(end_t-start_t);

	mu_assert( array[0] == 1 && array[8] == 9,\
		 "Failed to shell sort the list.");
	free(array);
	
	return NULL;
}

char *test_list_reverse()
{
	List_push(list, test1);
	List_push(list, test2);
	List_push(list, test3);
	List_push(list, test4);
	List_push(list, test5);

	list_reverse(list);	

	print_list(list);

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
	mu_run_test(test_create);
	mu_run_test(test_upside);
	mu_run_test(test_destroy);
	mu_run_test(test_create);
	mu_run_test(test_insert);
	mu_run_test(test_destroy);
	mu_run_test(test_shell);
	mu_run_test(test_create);
	mu_run_test(test_list_reverse);
	mu_run_test(test_destroy);

	
	return NULL;
}

RUN_TESTS(all_tests);


