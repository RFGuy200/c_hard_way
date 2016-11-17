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
				right->first = cur->next;
				left->last = cur;
			}
		}
		printf("count left = %d\n", left->count);
		printf("count right = %d\n", right->count);
		merge_sort(left);
		merge_sort(right);
	}
}
		
	
			
List *merge_list(List *left, List *right)
{
	List *sorted = List_create();
	ListNode *cur_left = left->first;
	ListNode *cur_right = right->first;
	sorted->first = malloc(sizeof(ListNode));
	ListNode *cur_sorted = sorted->first;
	Listnode *next = NULL;

	do{
		if(cur_left->value < cur_right->value){
			cur_sorted->value = cur_left->value;
			cur_left = cur_left->next;
		}else{
			cur_sorted->value = cur_right->value;
			cur_right = cur_right->next;
		}
		next = malloc(sizeof(ListNode));
		cur_sorted->next = next;
	}while(cur_left != left->last && cur_right != right->last);

	if(cur_left == left->last){
		do{
			cur_sorted->value = cur_right->value;
			cur_right = cur_right->next;	
			next = malloc(sizeof(ListNode));
			cur_sorted->next = next;
		}while(cur_right != right->last);
	}

	if(cur_right == right->last){
		do{
			cur_sorted->value = cur_left->value;
			cur_left = cur_left->next;	
			next = malloc(sizeof(ListNode));
			cur_sorted->next = next;
		}while(cur_left != left->last);
	}
	return sorted;
}



			
			
			
