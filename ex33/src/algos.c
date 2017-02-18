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
			&& strcmp(cur_left->value, cur_right->value) > 0){
			List_push(temp,cur_right->value);
			cur_right = cur_right->next;
			j++;
		}else if( j < right->count && k < left->count\
			&& strcmp(cur_left->value, cur_right->value) < 0){
			List_push(temp, cur_left->value);
			cur_left = cur_left->next;
			k++;
		}else if( j == right->count && k < left->count){
			List_push(temp, cur_left->value);
			k++;
		}else if( k == left->count && j < right->count){
			List_push(temp, cur_right->value);
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
