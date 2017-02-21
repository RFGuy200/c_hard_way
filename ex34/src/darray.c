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

int DArray_expand(DArray *array)
{
	int old_max = array->max;

	check(DArray_resize(array, array->expand_rate + old_max) == 0,\
		"Failed to expand array to nes size: %d.", \
		(int) array->expand_rate + old_max);

	memset(array->contents[old_max], 0, array->expand_rate);
	return 0;
error:
	return -1;
}

int DArray_contract(DArray *array)
{
	int new_size = array->end + 1  > (int) array->expand_rate ?\
			 array->end + 1 : (int) array->expand_rate;
	return DArray_resize(array, new_size);
}

int DArray_push(DArray *array, void *el)
{
	array->end++;
	array->contents[end] = el;


	if(DArray_end(array) >= DArray_max(array)){
		return DArray_expand(array);
	}else{
		return 0;
	}
}
 
		
