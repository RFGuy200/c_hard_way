#include "darray.h"
#include <assert.h>

Darray* Darray_create(size_t element_size, size_t initial_max)
{
	check(element_size > 0 && initial_max > 0, "USAGE: element size and initial_max have to\
		be more than 0");
	Darray *array = malloc(sizeof(Darray));
	check_mem(array);
	array->max = initial_max;

	array->contents = calloc(initial_max,  sizeof(void*));
	check_mem(array->contents);

	array->end = 0;
	array->element_size = element_size;
	array->expand_rate = DEFAULT_EXPAND_RATE;

	return array;
error:
	if(array)
		free(array);
	return NULL;
}

