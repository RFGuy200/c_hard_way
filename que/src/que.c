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

void Que_push(que* que, int value)
{
	check(que != NULL, "Que is NULL, can't push.");

	if(que->front == -1){
		que->front++;
		que->tail++;
		que->data[que->front] = value;
	}else{
		int i = (que->tail + 1) % MAX_SIZE;
		if(i == que->front){
			printf("\nQue ran out of space.\n");
			return;
		}else{
			que->data[i] = value;
			que->tail = i;
		}
	}
	return;

error:
	exit(-1);
}

int Que_pop(que *que)
{
	check(que->front || que->tail != -1, "Can't pop empty que.");

	int value = que->data[que->front];
	que->data[que->front] = 0;
	if(que->tail == que->front) {
		que->front = -1;
		que->tail = -1;
	}else{
		que->front = (que->front +1) % MAX_SIZE;
	}

	return value;

error:
	return -1;
}
