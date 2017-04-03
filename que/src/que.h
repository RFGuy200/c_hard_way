#include <stdio.h>
#include <dbg.h>

#define MAX_SIZE 100

typedef struct que{
	int *data;
	int front;
	int tail;
}que;

que* Que_create();
void Que_destroy(que *que);

void Que_push(que *que, int value);
int Que_pop(que *que);

