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
		int i = que->tail + 1;
		if(i > MAX_SIZE){
			printf("\nQue ran out of space.\n");
			return;
		}
		for(;i > 0; i--){
			que->data[i] = que->data[i-1];
		}
		que->data[que->front] = value;
		que->tail++;
	}
	return;

error:
	exit(-1);
}

int Que_pop(que *que)
{
	check(que->front || que->tail != -1, "Can't pop empty que.");

	int value = que->data[que->tail];
	que->data[que->tail] = 0;
	if(que->tail == que->front) {
		que->front = -1;
		que->tail = -1;
	}else{
		que->tail--;
	}

	return value;

error:
	return -1;
}
