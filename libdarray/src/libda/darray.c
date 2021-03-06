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

void Darray_clear(Darray *array)
{
	int i = 0;
	if(array->element_size > 0){
		for(i = 0; i < array->max; i++){
			if(array->contents[i] != NULL){
				free(array->contents[i]);
			}
		}
	}
}

static inline int Darray_resize(Darray *array, size_t newsize)
{
	check(newsize > 0, "New array size must be > 0");
	array->max = newsize;

	void *contents = realloc( array->contents, array->max*sizeof(void *));
	check_mem(contents);

	array->contents = contents;

	return 0;
error:
	return -1;
}

int Darray_expand(Darray *array)
{
	size_t old_max = array->max;
	check(Darray_resize(array, array->max + array->expand_rate) == 0, "Failed to expand array\
		to a new size: %d", array->max + array->expand_rate);

	memset(array->contents + old_max, 0, array->expand_rate + 1);

	return 0;
error:
	return -1;
}

int Darray_contract(Darray *array)
{
	int new_size = array->end < (int)array->expand_rate ? (int)array->expand_rate:\
		array->end;

	return Darray_resize(array, new_size + 1);
}

void Darray_destroy(Darray* array)
{
	if(array){
		if(array->contents)
			free(array->contents);
		free(array);
	}
}

void Darray_clear_destroy(Darray *array)
{
	Darray_clear(array);
	Darray_destroy(array);
}

int Darray_push(Darray * array, void *el)
{
	array->contents[array->end] = el;
	array->end++;

	if(Darray_end(array) >= Darray_max(array)){
		return	Darray_expand(array);
	}else{
		return 0;
	}
}

void *Darray_pop(Darray *array)
{	
	check(array->end -1 >= 0, "Attempt to pop from empty array");

	void *el = Darray_remove(array, array->end -1);
	array->end--;
	
	if(Darray_end(array) > (int)array->expand_rate &&\
		Darray_end(array) % array->expand_rate)
			Darray_contract(array);

	return el;
error:
	return NULL;
}

void  Darray_shift(Darray *array)
{
	check(array->end -1 >= 0, "Attempt to shift empty array");
	
	int i = 0;

	for(i = 0; i < array->end -1; i++){
		int *el = Darray_new(array);
		el = array->contents[i+1];
		Darray_set(array, i, el);
	}
	
	int *val = Darray_pop(array);
	free(val);
error:
	return NULL;

}
