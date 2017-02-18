#ifndef darray_h
#define daaray_h

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
}

DArray *DArray_create( size_t element_size, size_t initial_max);

void DArray_destroy(DArray *array);

void DArry_clear(DArray *array);

int DArray_expand(DArray *array);

int DArray_contract(DArray *array);

int DArray_push(DArray *array);

void DArray_pop(*DArray *array);

void DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end - 1])

#define DArray_first(A) ((A)->contents[0])

#define DArray_end(A) ((A)->end)

#define DArray_count(A) ((A)->end)

#define DArray_max(A) ((A)->max)

static inline void DArray_set(DArray *array, int i, void *el)


#endif
