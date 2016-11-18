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
	List *sorted = List_create();
	merge_split(list, sorted);

	LIST_FOREACH(sorted, first, next, cur){
		printf("%d, ", cur->value);
	}

}
	


void merge_split(List *list, List *sorted)
{

	List *left = NULL;
	List *right = NULL;
	int i = 0;
	int left_count = list->count/2;

	if (left_count > 0){
		left = List_create();
		right = List_create();

		LIST_FOREACH(list, first, next, cur){

			if(i < left_count){
				 List_push(left, cur->value);
			}else{ 
				List_push(right, cur->value);
			}		
			i++;
		}
			
		printf("left->first: %d, left->last: %d, right->first: %d, right->last: %d\n", left->first->value,\
			left->last->value, right->first->value, right->last->value);
		merge_split(left, sorted);
		merge_split(right, sorted);
		merge_list(left, right, sorted);
	}
}


		
	
			
List *merge_list(List *left, List *right, List *sorted)
{

	do{
		if(left->first->value < right->first->value){
			List_push(sorted, left->first->value);
			List_shift(left);
		}else{
			List_push(sorted, right->first->value);
			List_shift(right);
		}
	}while(left->count > 1 &&  right->count > 1);

	return sorted;
}



			
			
			
