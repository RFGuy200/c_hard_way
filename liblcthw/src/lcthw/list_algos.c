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


void merge_sort(List *list)
{

	List *left = NULL;
	List *right = NULL;
	int i = 0;
	int left_count = list->count/2;
	printf("count left = %d\n", left_count);
	printf("count right = %d\n", list->count - left_count);


	if (left_count > 1 || left_count == 1){
		left = List_create();
		right = List_create();
		left->first = list->first;
		right->last = list->last;
		left->count = left_count;
		right->count = list->count - left_count;
		LIST_FOREACH(list, first, next, cur){
			i++;
			if(i == left_count){
				right->first = cur->next;
				left->last = cur;
			}
		}
		merge_sort(left);
		merge_sort(right);


	}
}
		
	
			
		
