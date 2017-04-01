#include "minunit.h"
#include <stack.h>

stack *my_stack = NULL;

stack_interface stack_api = {\
	.create = create_fn,\
	.destroy = destroy_fn,\
	.push = push_fn,\
	.pop = pop_fn\
};

char *test_demo(){

	return NULL;
}

char *test_create(){

	my_stack = create_fn();

	return NULL;
}

char *test_destroy(){
	destroy_fn(my_stack);

	return NULL;
}

char *test_push(){
	push_fn(my_stack, 1);
	mu_assert(my_stack->data[my_stack->top] == 1, "1st cell should contain 1.");
	push_fn(my_stack, 2);
	mu_assert(my_stack->data[my_stack->top] == 2, "1st cell should contain 2.");
	push_fn(my_stack, 3);
	mu_assert(my_stack->data[my_stack->top] == 3, "1st cell should contain 3.");

	return NULL;
}

char *test_pop(){
	int value = pop_fn(my_stack);
	mu_assert(value == 3, "Pop should return 3.");
	value = pop_fn(my_stack);
	mu_assert(value == 2, "Pop should return 2.");
	value = pop_fn(my_stack);
	mu_assert(value == 1, "Pop should return 1.");

	return NULL;
}

char *test_api(){
	stack *my_new_stack = stack_api.create();
	stack_api.push(my_new_stack, 1);
	stack_api.push(my_new_stack, 2);
	stack_api.push(my_new_stack, 3);
	int value = stack_api.pop(my_new_stack);
	mu_assert(value == 3, "API pop should return 3.");
	value = stack_api.pop(my_new_stack);
	mu_assert(value == 2, "API pop should return 2.");
	value = stack_api.pop(my_new_stack);
	mu_assert(value == 1, "API pop should return 1.");

	return NULL;
}


char *all_tests(){

	mu_suite_start();

	mu_run_test(test_demo);
	mu_run_test(test_create);
	mu_run_test(test_push);
	mu_run_test(test_pop);
	mu_run_test(test_destroy);
	mu_run_test(test_api);
	
	return NULL;
}

RUN_TESTS(all_tests);


