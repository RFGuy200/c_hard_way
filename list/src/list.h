#ifndef list_h
#define list_h

#include <dbg.h>

typedef struct ListNode{
	struct ListNode *next;
	void *data;
}ListNode;

typedef struct List{
	ListNode *first;
	ListNode *last;
	int count;
}List;

List* List_create();
void List_destroy(List* list);

void List_push(List *list, void *value);

void List_reverse(List *list);


#endif

