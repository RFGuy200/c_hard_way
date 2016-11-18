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
	merge_split(list);


}
	


void merge_split(List *list)
{
	List *left = NULL;
	List *right = NULL;
	int i = 0;
	int left_count = list->count/2;

	if (left_count > 0){
		left = List_create();
		right = List_create();
		left->first = list->first;
		right->last = list->last;
		left->count = left_count;
		right->count = list->count - left_count;

		LIST_FOREACH(list, first, next, cur){
			i++;
			if(i == left_count){
				left->last = cur;
				right->first = cur->next;	
			}		
		}			
		printf("left->count: %d, left->first: %d, left->last: %d\nright->count: %d,\
right->first: %d, right->last: %d\n",left->count,  left->first->value,\
			left->last->value, right->count,  right->first->value, right->last->value);

		merge_split(left);
		merge_split(right);
		merge_list(left, right);
	}
}



		
	
			
List *merge_list(List *left, List *right)
{
	ListNode *cur_left = left->first;
	ListNode *cur_right = right->first;
	List *temp = List_create();
	int i = left->count;
	int j = right->count; 

	do{
		if(cur_left->value < cur_right->value){
			List_push(temp, cur_left->value);
			cur_left = cur_left->next;
			i--;
		}else{
			List_push(temp, cur_right->value);
			cur_right = cur_right->next;
			j--;
		}
	}while(i > 0 && j > 0);

	while(j == 0 && i > 0){
		List_push(temp, cur_left->value);
		cur_left = cur_left->next;	
		i--;
	}

	while(i == 0 && j > 0){
		List_push(temp, cur_right->value);
		cur_right = cur_right->next;	
		j--;
	}

	cur_left = left->first;

	LIST_FOREACH(temp, first, next, cur){
		cur_left->value = cur->value;
		cur_left = cur_left->next;
	}
	
}



			
			
			
