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

StackList* List_create()
{
	StackList *new = malloc(sizeof(StackList));
	check_mem(new);
	new->count = 0;
	new->top = NULL;

	return new;

error:
	return NULL;
}

void List_destroy(StackList *list)
{
	check(list, "Can't destroy NULL list.");
	ListNode *cur = NULL;

	while(list->top){
		cur = list->top->next;
		free(list->top);
		list->top = cur;
	}
	
	free(list);

error:
	return;
}

void List_push(StackList *stack, char value)
{
	ListNode *new_node = malloc(sizeof(ListNode));
	check_mem(new_node);

	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->count++;
error:
	return;
}

char List_pop(StackList *stack)
{
	check(stack->top != NULL, "Can't pop empty stack.");

	char value = stack->top->value;
	ListNode *cur = stack->top;
	stack->top = stack->top->next;
	free(cur);
	stack->count--;

	return value;
	
error:
	return -1;
}

int check_balance(StackList *stack, char *string)
{

	char *cur = &string[0];
	char last = 0;
	
	while(*cur != '\0'){
		switch (*cur){
			case '(':
				List_push(stack, *cur);
				cur++;	
				break;
			case')':
				last = List_pop(stack);
				check(last == '(', "Expression not balanced");
				cur++;					
				break;
			case'{':
				List_push(stack, *cur);
				cur++;
				break;
			case'}':
				last = List_pop(stack);
				check(last == '{', "Expression not balanced");
				cur++;	
				break;
			case'[':
				List_push(stack, *cur);
				cur++;
				break;
			case']':
				last = List_pop(stack);
				check(last == '[', "Expression not balanced");
				cur++;	
				break;
			default:
				cur++;
				continue;
		}
	}

	return 0;
error:
	return -1;
}
