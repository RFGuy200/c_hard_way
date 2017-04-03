#include <que.h>

que* Que_create()
{
	que* new = malloc(sizeof(que));
	check_mem(new);

	new->data = calloc(MAX_SIZE, sizeof(int));
	new->front = -1;
	new->tail = -1;

	return new;

error:
	return NULL;
}

void Que_destroy(que *que)
{
	check(que != NULL, "Que pointer is NULL, can't use destroy.");

	free(que->data);
	free(que);
	return;

error:
	exit(-1);
}
