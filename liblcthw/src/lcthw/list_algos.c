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


int already_sorted(List *list)
{
	int sorted = 1;
	int node_num = 0;
	ListNode *cur_node = list->first;

	for(node_num = 1; node_num < list->count; node_num++){
		if(cur_node->next->value < cur_node->value){
			sorted = 0;
		}
		cur_node = cur_node->next;
	}
	return sorted;
}
	

int bubble_sort(List *list)
{
	assert(list != NULL && "Can't sort NULL list");	

	int i = 0;

	if(already_sorted(list)){
		printf("Bubble list is already sorted\n");
	}else{
		for(i = 0; i < list->count; i++){
			 node_swap(list);
		}
	}
	return 0;
}

void merge_sort(List *list)
{
	if(already_sorted(list)){
		printf("Merge list is already sorted\n");
	}else{
		merge_split(list);
		if(already_sorted(list)){
			printf("List was successfully sorted!\n");
		}
	}
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

		merge_split(left);
		merge_split(right);
		merge_list(left, right);
		free(left);
		free(right);
	}
}
			
void merge_list(List *left, List *right)
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
	
	List_clear_destroy(temp);
	
}

void bu_merge(List *list)
{
	List *temp = List_create();
	int i = 0;
	int width = 0;
		
	for( width = 1; width < list->count; width *= 2){
		printf("width: %d\n", width);
		for( i = 0; i < list->count; i += 2*width){
			printf("i: %d\n", i);	
			bu_sort(list, temp, i, width);
		}
	}
}  
	
void bu_sort(List *list, List *temp, int i, int width){

	List *left = List_create();
	List *right = List_create();
	ListNode *cur_left = NULL;
	ListNode *cur_right = NULL;
	int counter = 0;

	for(counter = i; counter < i+2*width; counter++)
		printf("%d, ", counter);

	printf("\n");
	
}	

			
			
			
