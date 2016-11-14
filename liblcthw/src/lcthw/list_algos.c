#include <list_algos.h>
#include <dbg.h>
#include <assert.h>
#include <list.h>


void node_swap(List *list){

	ListNode *next_node = NULL;
	void *value = NULL;

	LIST_FOREACH(list, first, next, cur) {
		next_node = cur->next;
		if(next_node != NULL && (cur->value - next_node->value > 0)){
			value = cur->value;
			cur->value = next_node->value;
			next_node->value = value;	
		}

	}
}


int bubble_sort(List *list)
{
	assert(list != NULL && "Can't sort NULL list");	

	int i = 0;

	for(i = 0; i < list->count; i++){
		 node_swap(list);
	}
	
	return 0;
}


