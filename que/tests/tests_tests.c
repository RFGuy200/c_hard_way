#include "minunit.h"
#include <que.h>

que *my_que = NULL;

char *test_create()
{
	my_que = Que_create();
	
	return NULL;
}

char *test_destroy()
{
	Que_destroy(my_que);

	return NULL;
}

char *test_push()
{
	Que_push(my_que, 1);
	mu_assert(my_que->front == 0 && my_que->tail == 0 && my_que->data[0] == 1,\
		"First number in que should be 1.");
	Que_push(my_que, 2);
	mu_assert(my_que->front == 0 && my_que->tail == 1 && my_que->data[0] == 2,\
		"First number in que should be 1.");
	Que_push(my_que, 3);
	mu_assert(my_que->front == 0 && my_que->tail == 2 && my_que->data[0] == 3,\
		"First number in que should be 1.");

	return NULL;
}
 
char *test_pop()
{
	int value = Que_pop(my_que);
	mu_assert(value == 1, "Pop should return 1.");
	value = Que_pop(my_que);
	mu_assert(value == 2, "Pop should return 2.");
	value = Que_pop(my_que);
	mu_assert(value == 3 &&  my_que->front  == -1 && my_que->tail == -1, "Pop should return 3.");

	return NULL;
}
	

char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_pop);
	mu_run_test(test_destroy);

	
	return NULL;
}

RUN_TESTS(all_tests);


