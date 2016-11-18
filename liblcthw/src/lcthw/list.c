
#include <list.h>
#include <dbg.h>
#include <assert.h>

List *List_create()
{

	return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
	assert(list != NULL && "Nothing to destroy, List is NULL");
	
	LIST_FOREACH(list, first, next, cur) {
		if(cur->prev){
			free(cur->prev);
		}
	}
	
	free(list->last);
	free(list);
}

void List_clear(List *list)
{
	assert(list != NULL && "Nothing to clear, List is NULL");
	
	LIST_FOREACH(list, first, next, cur){
	cur->value = NULL;
	}
}

void List_clear_destroy(List *list)
{
	assert(list != NULL && "Nothing to clear and destroy, List is NULL");

	List_clear(list);
	List_destroy(list);

}

void List_push(List *list, void *value)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if(list->last == NULL){
		list->first = node;
		list->last = node;
	}else{
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;
error:
	return;
}

void *List_pop(List *list)
{
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if(list->first == NULL){
		list->first = node;
		list->last = node;
	}else{
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}
	
	list->count++;
error:
	return;
}

void *List_shift(List *list)
{
	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
	assert(list != NULL && "Can't remove from NULL list");

	void *result = NULL;

	check(list->first && list->last, "List is empty");
	check(node, "Node can't ne NULL");

	if(node == list->first && node == list->last){
		list->first = NULL;
		list->last = NULL;
	}else if(node == list->first){
		list->first = node->next;
		check(list->first != NULL, "Invalid list, somehow got a first that is NULL");
		list->first->prev = NULL;
	}else if(node == list->last){
		list->last = node->prev;
		check(list->last != NULL, "Invalid list, somehow got a next that is NULL");
		list->last->next = NULL;
	}else{
		ListNode *before = node->prev;
		ListNode *after = node->next;
		after->prev = before;
		before->next = after;
	}
	
	list->count--;
	result = node->value;
	free(node);
	return result;	

error:
	return result;
}

List *List_copy(List *list)
{
	assert(list != NULL && "Nohing to copy, the list does not exist");
	
	List *new_list = calloc(1, sizeof(List));
	check(new_list != NULL, "Error creating a new list");

	ListNode *new_node = calloc(1, sizeof(ListNode));
	check(new_node != NULL, "Error creating the first node");

	new_list->first = new_node;
	new_list->count++;

	LIST_FOREACH(list, first, next, cur){
		new_node->value = cur->value;		
		if(cur->next){
			ListNode *next = calloc(1, sizeof(ListNode));
			check(next != NULL, "Error creating next node");
			new_node->next = next;
			next->prev = new_node;
			new_node = next;
			new_list->count++;
		}
	}
	
	new_list->last = new_node;
	
	return new_list;
error:
	return NULL;

}
	
void List_join(List *list, List *next)
{
	assert(list != NULL && next != NULL && "Can't join, one or both lists are empty");

	list->last->next = next->first;
	next->first->prev = list->last;
	list->last = next->last;
	list->count += next->count;
	free(next);
}

List *List_split(List *list, int split)
{
	assert(list != NULL && "Can't split NULL list");
	assert(split > 0 && split < List_count(list) && "USAGE: 0 < split < list count");

	List *new_list = calloc(1, sizeof(List));
	check_mem(new_list);

	ListNode *split_node = list->first;
	ListNode *split_prev = NULL;
	int i = 0;
	
	for(i = 0; i < split; i++){
		split_prev = split_node;
		split_node = split_prev->next;
	}
	
	new_list->first = split_node;
	new_list->first->prev = NULL;
	new_list->last = list->last;
	new_list->count = List_count(list) - split;
	list->last = split_prev;
	list->last->next = NULL;
	list->count = split;

	return new_list;

error:

	return NULL;
}
	
