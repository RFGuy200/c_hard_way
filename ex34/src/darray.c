#include <darray.h>

DArray *DArray_create(size_t element_size, size_t initial_max )
{
	assert(initial_max > 0 && "You must set initial max > 0.");

	DArray *new = calloc(1, sizeof(DArray));
	check_mem(new);
	
	new->end = 0;
	new->max = initial_max;
	new->element_size = element_size;
	new->expand_rate = DEFAULT_EXPAND_RATE;
	new->contents = calloc(initial_max, sizeof(void*));
	check_mem( new->contents);	
	
	return new;
error: 
	if(new)
		free(new);
	return NULL;
}

void DArray_destroy(DArray *array)
{
	assert(array != NULL && "Can't destroy array that is NULL.");

	if(array){
		if(array->contents)
			free(array->contents);
		free(array);
	}
}

int DArray_resize(DArray *array, size_t new_size)
{
	assert(new_size > 0 && "new size must be >0.");

	array->max = new_size;

	void *contents = realloc(array->contents, sizeof(void*) * array->max);
	check_mem(contents);

	array->contents = contents;

	return 0;
error:
	return -1;
}

int DArray_expand(DArray *array)
{
	size_t old_max = array->max;

	int resize = DArray_resize(array, array->expand_rate + array->max);

	check(resize == 0,"Failed to expand array to nes size: %d.", \
		(int) array->expand_rate + (int) old_max);

	memset(array->contents + old_max + 1, 0, array->expand_rate);
	return 0;
error:
	return -1;
}

int DArray_contract(DArray *array)
{
	int new_size = array->end  > (int) array->expand_rate ?\
			 array->end : (int) array->expand_rate;
	return DArray_resize(array, new_size);
}

void DArray_push(DArray *array, void *el)
{
	array->end++;
	
	if(array->end >= array->max)
		DArray_expand(array);

	array->contents[array->end - 1] = el;
}

void *DArray_pop(DArray *array)
{
	check(array->end > 0, "Attempt to pop from empty array."); 

	void *el = DArray_remove(array, array->end - 1);
	array->end--;

	return el;
error:
	return NULL;
}
 
		
