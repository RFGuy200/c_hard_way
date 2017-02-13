#include <algos.h>


int cmp_func(ListNode *node1, ListNode *node2)
{

	return strcmp(node1->value, node2->value);
}

void bubble_sort(List *list)
{
	int i = 0;
	
	for(i = 1; i < list->count - 1; i++){
		LIST_FOREACH(list, first, next, cur){
			if(cur->next->next == NULL){
				break;
			}else if(cmp_func(cur, cur->next)){
				char *value = cur->value;
				cur->value = cur->next->value;
				cur->next->value = value;
			}
		}
	}			
}
