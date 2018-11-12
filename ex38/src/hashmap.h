#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>
#include <darray.h>

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int ( *hashmapCompare ) ( void *a, void *b);
typedef uint32_t ( *hashmapHash ) ( void *key);

typedef struct Hashmap 
{
	DArray *buckets;
	hashmapCompare compare;
	hashmapHash hash;
} Hashmap;

typedef struct HashmapNode
{
	void *key;
	void *data;
	uint32_t hash;	
} HashmapNode;

typedef int ( *hashmapTraverseCb ) ( HashmapNode *node );

Hashmap* hashmapCreate( hashmapCompare Hashmap, hashmapHash hash );

void hashmapDestroy( Hashmap *map );
int hashmapSet( Hashmap *map, void *key, void *data );
void* hashmapGet( Hashmap *map, void *key );
int hashmapTraverse( Hashmap *map, hashmapTraverseCb traverseCb );
void* hashmapDelete( Hashmap *map, void *key );

#endif // HASHMAP_H
