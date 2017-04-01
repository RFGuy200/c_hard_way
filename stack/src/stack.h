#include <stdio.h>
#include <stdlib.h>
#include <dbg.h>

#define MAX_SIZE 100


typedef struct stack{
	int *data;
	int top;
	int allocated;
}stack;

typedef struct stack_api{
	stack* (*create)();
	void (*destroy)(stack *stack);
	void (*push)(stack *stack, int value);
	int (*pop)(stack *stack);	
}stack_interface;

stack* create_fn();
void destroy_fn(stack* stack);

void push_fn(stack *stack, int value);
int pop_fn(stack *stack);


