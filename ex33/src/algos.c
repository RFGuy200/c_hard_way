#include <algos.h>


int cmp_func(ListNode *node1, ListNode *node2)
{

	return strcmp(node1->value, node2->value);
}

void bubble_sort(List *list)
{
	int i = 0;
	
	for(i = 0; i < list->count - 1; i++){
		LIST_FOREACH(list, first, next, cur){
			if(cur->prev && cmp_func(cur->prev, cur) > 0){
				char *value = cur->value;
				cur->value = cur->prev->value;
				cur->prev->value = value;
			}
		}
	}			
}	
