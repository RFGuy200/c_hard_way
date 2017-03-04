#ifndef darray_h
#define darray_h

#include <stdlib.h>
#include <assert.h>
#include <dbg.h>


#define DEFAULT_EXPAND_RATE 300

typedef struct DArray{
	int end;
	int max;
	size_t element_size;
	size_t expand_rate;
	void **contents;
}DArray;

DArray *DArray_create( size_t element_size, size_t initial_max);

void DArray_destroy(DArray *array);

void DArry_clear(DArray *array);

int DArray_expand(DArray *array);

int DArray_contract(DArray *array);

void DArray_push(DArray *array, void *el);

void *DArray_pop(DArray *array);

void DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end - 1])

#define DArray_first(A) ((A)->contents[0])

#define DArray_end(A) ((A)->end)

#define DArray_count(A) ((A)->end)

#define DArray_max(A) ((A)->max)

static inline void *DArray_set(DArray *array, int i, void *el)
{
	check(i < array->max - 1, "Attempt to set past max.");
	if(i > array->end - 1) 
		array->end = i + 1;
	array->contents[i] = el;

	return el;
error:
	return NULL;
}

static inline void *DArray_get( DArray *array, int i)
{
	check(i < array->max, "Attempt to get past max.");
	return array->contents[i];
error:
	return NULL;
}

static inline void *DArray_remove( DArray *array, int i)
{
	check(i < array->max, "Attempt to remove past max.");
	void *el = array->contents[i];
	array->contents[i] = NULL;
	return el;
error:
	return NULL;
}	

static inline void *DArray_new(DArray *array)
{
	check(array->element_size > 0, "Element size has to be > 0.");
	return calloc(1, array->element_size);
error:
	return NULL;
}



#define DArray_free(A) free((A))

#endif
