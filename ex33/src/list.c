#include <list.h>
#include <dbg.h>
#include <assert.h>

List *List_create()
{
	return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
	assert(list != NULL && "Failed to destroy, List can't be NULL");
	LIST_FOREACH(list, first, next, cur){
		if(cur->prev)
			free(cur->prev);
	}
	if(list->last)
		free(list->last);
	free(list);
}


void List_push(List *list, void *value)
{
	assert( list != NULL && "Can't push if list is NULL");
	
	ListNode *new = calloc(1, sizeof(ListNode));
	assert (new != NULL && "Can't create a Node.");
	new->value = value;
	ListNode *first = list->first;

	if(list->count == 0){
		list->count++;
		list->first = new;
		list->last = new;
	}else{
		new->prev = list->last;
		list->last->next = new;
		list->last = new;
		list->first = first;
		list->count++;
	}

}

void List_pop(List *list)
{
	assert(list !=NULL && "Can't pop from NULL list.");

	if(list->count == 0){
		printf("List is already empty, nothing to pop");
	}else if(list->count == 1){
		free(list->last);
		list->last = NULL;
		list->first = NULL;
		list->count--;

	}else{
		list->last = list->last->prev;
		free(list->last->next);
		list->last->next = NULL;
		list->count--;
	}
}	

void List_unshift(List *list, void *value)
{
	assert(list != NULL &&"Can't shift if list is NULL");

	ListNode *new = calloc(1, sizeof(ListNode));
	assert(new != NULL &&"Cant create a Node.");

	new->value = value;

	if(list->count == 0){
		list->first = new;
		list->last = new;		
	}else{
		list->first->prev = new;
		new->next = list->first;
		list->first = new;
	}
	
	list->count++;
}

void List_shift(List *list)
{
	assert(list != NULL &&"Can't shift if list is NULL.");

	if(list->count == 0){
		printf("List is already empty");
	}else if(list->count == 1){
		list->first = NULL;
		list->last = NULL;
		list->count--;
	}else{
		list->first = list->first->next;
		free(list->first->prev);
		list->first->prev = NULL;
		list->count--;
	}
}

void List_remove(List *list, ListNode *node)
{
	if(node == list->first){
		List_shift(list);
	}else if(node == list->last){
		List_pop(list);
	}else{
		ListNode *prev = node->prev;
		ListNode *next = node->next;
		prev->next = node->next;
		next->prev = node->prev;
		list->count--;
		free(node);
	}
}

void List_insert_before(List *list, ListNode *before, ListNode *insert)
{

	if(before == list->first){
		List_unshift(list, insert->value);
		List_remove(list, insert);
	}else if(insert ==  list->last){
		list->last = list->last->prev;
		insert->prev->next = NULL;
		before->prev->next = insert;
		insert->prev = before->prev;
		insert->next = before;
		before->prev = insert;
	}else{ 
		insert->prev->next = insert->next;
		insert->next->prev = insert->prev;
		before->prev->next = insert;
		insert->prev = before->prev;
		insert->next = before;
		before->prev = insert;
	}
}

	
