#include <list.h>
#include <stdlib.h>
#include <assert.h>

List* List_create()
{
	List* list = malloc(sizeof(List));
	check_mem(list);

	list->first = NULL;
	list->last = NULL;
	list->count = 0;

	return list;

error:
	exit(EXIT_FAILURE);
}

void List_destroy(List *list)
{
	assert(list != NULL && "Can't destroy NULL list.");

	ListNode *cur = list->first;
	ListNode *next = NULL;

	while(cur->next != NULL){
			next = cur->next;
			free(cur);
			cur = next;
	}
	free(cur);
	free(list);
}

void List_push(List *list, void *value)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	node->data = value;

	if(list->count == 0){
		list->first = node;
		list->last = node;
	}else{
		list->last->next = node;
		list->last = node;
	}
	
	list->count++;	
}

void List_reverse( List *list)
{
	if(list->count < 2)
		return;

	ListNode *cur = list->first;
	ListNode *next = cur->next;
	cur->next = NULL;
	ListNode *temp = NULL;

	while(next != NULL){
		temp = next->next;
		next->next = cur;
		cur = next;
		next = temp;
	}

	list->last = list->first;
	list->first = cur;
}
