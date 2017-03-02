#include <darray_algos.h>
#include <array.h>
#include <minunit.h>


char *test_qsort()
{
	return run_sort_test(DArray_qsort, "quick sort");
}

char *test_heapsort()
{
	return run_sort_test(DArray_heapsort, "heap sort");
}

char *test_mergesort()
{
	return run_sort_test(DArray_mergesort, "merge sort");
}
	


char *all_tests(){

	mu_suite_start();

	mu_run_test(test_create);
	
	return NULL;
}

RUN_TESTS(all_tests);
