#ifndef _Darray_h
#define _Darray_h
#include <stdlib.h>
#include <assert.h>
#include <dbg.h>

#define DEFAULT_EXPAND_RATE 300

typedef struct Darray{
	int end;
	int max;
	size_t element_size;
	size_t expand_rate;
	void **contents;
} Darray;

Darray* Darray_create(size_t element_size, size_t initial_max);
/*

void Darray_destroy(Darray* array);

void Darray_clear(Darray* array);

int Darray_expand(Darray* array);

int Darray_contract(Darray* array);

int Darray_push(Darray* array, void *el);

void Darray_pop(Darray* array);

void Darray_clear_destroy(Darray* array);

#define Darray_last(A) ((A)->contents[(A)->end-1])
#define Darray_first(A) ((A)->contents[0])
#define Darray_end(A) ((A)->end)
#define Darray_count(A) Darray_end(A)
#define Darray_max(A) ((A)->max)

inline static void Darray_set(Darray *array, int i, void *el){
	check(i < array->max, "darray attempt to set past max");
	if(i > array->end)
		array->end = i;
	array_contents[i] = el;
error:
	return;
}

inline static void* Darray_get(Darray *array, int i){
	check(i < array->end, "darray attempts to get past max");
	return	array->contents[i];
error:
	return;
}

static inline void *Darray_remove(Darray *array, int i){
	check(i < array->end, "darray attempts to remove past max");
	void *el = array->contents[i];
	array->contents[i] = NULL;
	return el;
error:
	return;
}
	
static inline void *Darray_new(Darray *array){
	check(array->element_size > 0, "Can't use Darray_new on 0 size darray");
	return calloc(1, array->element_size);
error:
	return;
}

#define Darray_free(E) free((E))
*/
#endif

