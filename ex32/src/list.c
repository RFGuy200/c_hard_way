#include <list.h>
#include <dbg.h>
#include <assert.h>

List *List_create()
{
	return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
	assert(list != NULL && "Failed to destroy, List can't be NULL");
	LIST_FOREACH(list, first, next, cur){
		if(cur->prev)
			free(cur->prev);
	}
	if(list->last)
		free(list->last);
	free(list);
}
