#include "minunit.h"
#include <assert.h>
#include <list.h>
#include <list_algos.h>

static List *list = NULL;
static List *copy = NULL;
static List *split = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

static List *bubble;
static List *merge;
int *array = (int[]){9,1,8,2,7,3,6,4};


void display_list(List *display)
{
	printf("List values:\n");		

	LIST_FOREACH(display, first, next, cur)
		if(cur->next != NULL){
			printf("%d, ", cur->value);
		}else{
			printf("%d", cur->value);
		}
		
	printf("\n");
}

char *create_list()
{
	bubble = List_create();
	merge = List_create();
	int i = 0;

	for(i = 0; i < 8; i++){
		List_push(bubble, *array);
		List_push(merge, *array);
		array++;
	}

	display_list(bubble);
	display_list(merge);

	return NULL;
}




char *destroy_list()
{
	List_clear_destroy(bubble);
	List_clear_destroy(merge);

	return NULL;
}

char *bubble_test()
{
	bubble_sort(bubble);
	display_list(bubble);

	return NULL;
}

char *merge_test()
{
	merge_sort(merge);

	return NULL;
}



char *test_create()
{
	list = List_create();
	mu_assert(list != NULL, "Failed to create list");

	return NULL;
}

char *test_destroy()
{

	List_clear_destroy(list);
	List_clear_destroy(split);
	
	return NULL;
}

char *test_push_pop()
{
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value");

	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value");

	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value");
	mu_assert(List_count(list) == 3, "Wrong count on push");

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong pop value");

	val = List_pop(list);
	mu_assert(val == test2, "Wrong pop value");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong pop value");
	mu_assert(List_count(list) == 0, "Wrong count after pop");	

	return NULL;
}


char *test_unshift()
{
	List_unshift(list, test1);
	mu_assert(List_first(list) == test1, "Wrong first value");

	List_unshift(list, test2);
	mu_assert(List_first(list) == test2, "Wrong first value");

	List_unshift(list, test3);
	mu_assert(List_first(list) == test3, "Wrong first value");
	mu_assert(List_count(list) == 3, "Wrong count on unshift");

	return NULL;

}

char *test_remove()
{
	//we only need to test middle case remove because
	//shift and unshift test the other cases

	char *val = List_remove(list, list->first->next);
	mu_assert(val == test2, "Wrong removed element");
	mu_assert(List_count(list) == 2, "Wrong count after remove");
	mu_assert(List_first(list) == test3, "Wrong first after remove");
	mu_assert(List_last(list) == test1, "Wrong last after remove");

	return NULL;
}

char *test_shift()
{
	mu_assert(List_count(list) != 0, "Wrong count before shift");

	char *val = List_shift(list);
	mu_assert(val == test3, "Wrong value on shift");

	val = List_shift(list);
	mu_assert(val == test1, "Wrong value on shift");
	mu_assert(List_count(list) == 0, "Wrong count after shift");

	return NULL;
}

char *test_copy()
{
	List_push(list, test1);
	List_push(list, test2);
	List_push(list, test3);
	
	copy = List_copy(list);

	mu_assert(copy != NULL && List_count(copy) == List_count(list)\
		&& List_first(copy) == List_first(list) && \
		List_last(copy) == List_last(list), "Failed to copy the list");

	return NULL;
}

char *test_join()
{
	int count = List_count(list) + List_count(copy);
	void *last_value = List_last(copy);

	List_join(list, copy);
	mu_assert(list->count == count &&\
		  List_last(list) == last_value, "Failed to join lists");

	return NULL;
}

char *test_split()
{
	split = List_split(list, 2);
	mu_assert(List_count(list) == 2 && List_count(split) == 4\
		, "Failed to split the list");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	mu_run_test(test_unshift);
	mu_run_test(test_remove);
	mu_run_test(test_shift);
	mu_run_test(test_copy);
	mu_run_test(test_join);
	mu_run_test(test_split);
	mu_run_test(test_destroy);

	mu_run_test(create_list);
	mu_run_test(bubble_test);
	mu_run_test(merge_test);
	mu_run_test(destroy_list);


	return NULL;
}

RUN_TESTS(all_tests);
