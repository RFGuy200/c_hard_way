#include <list_algos.h>
#include <dbg.h>
#include <assert.h>
#include <list.h>

int bubble_sort(List *list)
{
	assert(list != NULL && "Can't sort NULL list");	

	int i = 0;
	ListNode *next = NULL;

	for(i = 0; i < list->count; i++){
		LIST_FOREACH(list, first, next, cur) {
			next = cur->next;
			if(next != NULL && (cur->value - next->value > 0)){
				next->prev = cur->prev;
				cur->next = next->next;
				cur->prev = next;
				next->next = cur;
				cur = next;
			}
		}
	}
	
	return 0;
}
