/* This is a test to try two different stack implementations: array and list. Also I tried to implement Object Oriented like approach to interface stack. Currently
have to choose which typedef to use in header file (list or array) and then initialize stack_api struct in caller with appropriate function pointers. Then 
stack can be accessed through stack_api only. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <dbg.h>

#define MAX_SIZE 100

typedef struct ListNode{
	int value;
	struct ListNode *next;
}ListNode;

typedef struct StackList{
	ListNode *top;
	int count;
}StackList;

typedef struct stack{
	int *data;
	int top;
	int allocated;
}stack;
/*
typedef struct stack_api{
	stack* (*create)();
	void (*destroy)(stack *stack);
	void (*push)(stack *stack, int value);
	int (*pop)(stack *stack);	
}stack_interface;
*/
typedef struct stack_api{
	StackList* (*create)();
	void (*destroy)(StackList *stack);
	void (*push)(StackList *stack, int value);
	int (*pop)(StackList *stack);	
}stack_interface;


stack* create_fn();
void destroy_fn(stack* stack);

void push_fn(stack *stack, int value);
int pop_fn(stack *stack);

StackList* List_create();
void List_destroy(StackList *list);
	
void List_push(StackList *stack, int value);
int List_pop(StackList *stack);


