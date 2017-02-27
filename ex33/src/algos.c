#include <algos.h>
#include <list.h>


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


void merge_sort(List *list)
{
	int mem_number =list->count / 2;
	int i = 0;
	ListNode *cur = NULL;

	List *left = List_create();
	List *right = List_create();

	left->count = mem_number;
	left->first = list->first;

	cur = left->first;
	for(i = 1; i < left->count; i++)
		cur = cur->next;

	left->last = cur;

	right->count = list->count - mem_number;
	right->first = left->last->next;

	cur = right->first;
	for(i = 1; i < right->count; i++)
		cur = cur->next;
	
	right->last = cur;

	if (left->count != 1)
		merge_sort(left);
	
	if (right->count != 1)
		merge_sort(right);

	merge(left, right);

	free(left);
	free(right);

}

void merge(List *left, List *right)
{

	ListNode *cur_left = left->first;
	ListNode *cur_right = right->first;
	List *temp = List_create();
	int count = left->count + right->count;
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < count; i++){
		if(j < right->count && k < left->count \
			&& strcmp(cur_left->value, cur_right->value) >= 0){
			List_push(temp,cur_right->value);
			cur_right = cur_right->next;
			j++;
		}else if( j < right->count && k < left->count\
			&& strcmp(cur_left->value, cur_right->value) < 0){
			List_push(temp, cur_left->value);
			cur_left = cur_left->next;
			k++;
		}else if( j >= right->count && k <= left->count){
			List_push(temp, cur_left->value);
			cur_left = cur_left->next;
			k++;
		}else if( k >= left->count && j <= right->count){
			List_push(temp, cur_right->value);
			cur_right = cur_right->next;
			j++;
		}
	}

	cur_left = left->first;
	ListNode *cur_temp = temp->first;

	for (i = 0; i < temp->count; i++){
		cur_left->value = cur_temp->value;
		cur_left = cur_left->next;
		cur_temp = cur_temp->next;
	}

	List_destroy(temp);
		
}	

void upside_merge(List *list)
{
	int len = 1;
	int i = 0;
	List *left = List_create();
	List *right = List_create();
	left->first = list->first;
	ListNode *cur = NULL;
	int cur_node = 0;
	
	for(len = 1; len * 2 < list->count; len *=2){
		cur_node = 0;
		left->first = list->first;

		while(list->count - cur_node > len * 2){
			left->count = len;
			right->count = len;

			cur = left->first;
			for(i = 1; i < left->count; i++)
				cur = cur->next;
			left->last = cur;
			right->first = left->last->next;
			cur = right->first;
			for(i = 1; i < right->count; i++)
				cur = cur->next;
			right->last = cur;
			merge(left, right);
			left->first = right->last->next;
			cur_node +=len * 2;
		}

		if(list->count - cur_node > len){
			right->count = list->count - cur_node - len;
			left->count = len;
			right->last = list->last;
			cur = left->first;
			for(i = 1; i < left->count; i++)
				cur = cur->next;
			left->last = cur;
			right->first = left->last->next;
			merge(left, right);
		}	

			
	}

	left->count = len;
	right->count = list->count - len;
	left->first = list->first;
	cur = left->first;
	for(i = 1; i < left->count; i++)
		cur = cur->next;
	left->last = cur;
	right->first = left->last->next;
	right->last = list->last;
	merge(left, right);


		
	free(left);
	free(right);

}	

void insert_sort(List *list)
{

	ListNode *cur_node = list->first->next;
	ListNode *prev_node = cur_node->prev;
	ListNode *new_cur = NULL;

	while(cur_node != NULL){
		prev_node = cur_node->prev;

		if(cur_node != list->last){
			new_cur = cur_node->next;
		}else{
			new_cur = NULL;
		}

		if(strcmp(cur_node->value, prev_node->value) < 0){
			while(prev_node != NULL){
				if(prev_node == list->first){
					List_insert_before(list, prev_node, cur_node);
					break;
				}else if(strcmp(cur_node->value, prev_node->prev->value) >= 0){
					List_insert_before(list, prev_node, cur_node);
					break;
				}else{
					prev_node = prev_node->prev;
				}
			}
		}
			cur_node = new_cur;

	}
}		

void shell_sort(List *list)
{
	int interval = 1;
	List *temp = NULL;
	int i = 0;
	int j = 0;
	ListNode *cur_node = NULL;
	
	while (interval < list->count/2){
		interval = interval *3 +1;
	}

	while(interval > 0){
		temp = List_create();
		temp->first = list->first;

		while (list->count - j >= interval){
			for(i = 0, i < interval; i++){
				cur_node = cur_node->next;
				j++;
			}
			List_push(temp, cur_node->value);
			
		}

		insert_sort(temp);		

		while(i < list->count){
			
	
		}
		List_destroy(temp);
		interval = (interval - 1)/3;
	}


}
