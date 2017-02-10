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
	mem_check(new);
	new->value = value;

	if(list->count == 0){
		list->count++;
		list->first = new;
		list->last = new;
	}else{
		list->last->next = new;
		list->last = new;
		list->count++;
	}
}


	
