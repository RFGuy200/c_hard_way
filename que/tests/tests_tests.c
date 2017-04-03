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


char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);


