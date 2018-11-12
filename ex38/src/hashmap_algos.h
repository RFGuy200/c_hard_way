##ifndef HASHMAP_ALGOS_H
#define HASHMAP_ALGOS_H

#include <stdint.h>

uint32_t hashmapFnv1aHash( void *data);
uint32_t hashmapAdler32Hash( void *data);
uint32_t hashmapDjbHash( void *data);

#endif // HASHMAP_ALGOS_H
