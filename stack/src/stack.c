#include <stack.h>

stack* create_fn()
{
	stack *new_stack = malloc(sizeof(stack));
	check_mem(new_stack);

	new_stack->data = calloc(MAX_SIZE, sizeof(int));
	new_stack->top = -1;
	new_stack->allocated = MAX_SIZE;
	
	return new_stack;
error:
	return NULL;
}

void destroy_fn(stack* stack)
{
	check(stack, "Can't destroy empty stack.");

	
	if(stack->data)
		free(stack->data);
	free(stack);

error: 
	return;
}

void push_fn(stack *stack, int value)
{
	check(stack->top < stack->allocated -1, "Stack is full, no more push is possible");

	stack->top++;
	stack->data[stack->top] = value;
error:
	return;
}

int pop_fn(stack *stack)
{
	check(stack->top != -1, "Can't pop empty stack.");

	int value = stack->data[stack->top];
	stack->data[stack->top] = 0;
	stack->top--;

	return value;

error:
	return -1;
}
		
