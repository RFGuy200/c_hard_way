#undef NDEBUG
#include <stdint.h>
#include "hashmap.h"
#include <dbg.h>
#include <bstrlib.h>

static int defaultCompare( void *a, void *b)
{
	return bstrcmp( a, b );
}

/* Simple Bob Jerkins's hash algorithm taken from
 * the wikipedia description.
 */

static uint32_t defaultHash( void *a)
{
	size_t len = blength( (bstring) a);
	char *key = bdata( (bstring) a);
	uint32_t hash = 0;
	uint32_t i = 0;

	for( i; i < len; ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += ( hash << 3 );
	hash ^= ( hash >> 11);
	hash += ( hash >> 6 );

	return hash;
}

Hashmap* hashmapCreate( hashmapCompare compare, hashmapHash hash)
{
	Hashmap *map = calloc( 1, sizeof(Hashmap) );
	check_mem(map);

	map->compare = (compare == NULL) ? defaultCompare : compare;
	map->hash = (hash == NULL) ? defaultHash : hash;
	map->buckets = DArray_create( sizeof(DArray*), DEFAULT_NUMBER_OF_BUCKETS );
	/* Fake out expanding it */
	map->buckets->end = map->buckets->max; 
	check_mem(map->buckets);

	return map;

error:
	if(map)
	{
		hashmapDestroy( map );
	}

	return NULL;
}

void hashmapDestroy( Hashmap *map)
{
	int i = 0;
	int j = 0;

	if( map )
	{
		if( map->buckets )
		{
			for( i = 0; i < DArray_count(map->buckets); i++ ) {
				 DArray *bucket = DArray_get( map->buckets, i );
				 if( bucket )
				 {
				 	for( j = 0; j < DArray_count(map->buckets); j++) {
				 		free( DArray_get(bucket, j) );
				 	}
				 	DArray_destroy( bucket );
				 }
			}
			DArray_destroy( map->buckets );
		}
		free(map);
	}
}

static inline HashmapNode* hashmapNodeCreate( int hash, void *key, void *data )
{
	HashmapNode *node = calloc( 1, sizeof(HashmapNode) );
	check_mem( node );

	node->key = key;
	node->data = data;
	node->hash = hash;

	return node;

error:
	return NULL;
}

static inline DArray* hashmapFindBucket( 	Hashmap *map, void *key, int create, uint32_t *hash_out )
{
	uint32_t hash = map->hash( key );
	int bucketN = hash % DEFAULT_NUMBER_OF_BUCKETS;

	check( bucketN >= 0, "Invalid bucket found: %d", bucketN);

	/* Store it for the return so the user can use it */
	*hash_out = hash;

	DArray *bucket = DArray_get( map->buckets, bucketN);

	if(!bucket && create)
		{
		/* new bucket set it up */
			bucket = DArray_create( sizeof(void), DEFAULT_NUMBER_OF_BUCKETS);
			check_mem(bucket);
			DArray_set(map->buckets, bucketN, bucket);
		}
	return bucket;

error:
	return NULL;
}

static int hashmapNodeCmp( const void *node1, const void *node2)
{
	int key1 = *(int*)node1->key;
	int key2 = *(int*)node2->key;
	return key1 - key2; 
}

int hashmapSet( Hashmap *map, void *key, void *data )
{
	uint32_t hash = 0;
	DArray *bucket = hashmapFindBucket( map, key, 1, &hash);
	check( bucket, "Error can't create bucket");
	
	HashmapNode *node = hashmapNodeCreate( hash, key, data);
	check_mem( node);

	DArray_push( bucket, node );

	printf( "*******************************\nBucket length = %i\n", bucket->end );

	if( bucket->end > 1 )
	{
		DArrayQuickSort( bucket, hashmapNodeCmp );
	}

	return 0;

error:
	return -1;

}

static inline int hashmapGetNode( Hashmap *map, uint32_t hash, DArray *bucket, void *key)
{
	int i = 0;

	for( i = 0; i < DArray_end(bucket); i++)
	{
		debug( "TRY: %d", i);
		HashmapNode *node = DArray_get( bucket, i );

		if( (node->hash == hash) && (map->compare(node->key, key) == 0) )
		{
			return i;
		}
	}
	return -1;
}

void* hashmapGet( Hashmap *map, void *key)
{
	uint32_t hash = 0;
	DArray *bucket = hashmapFindBucket( map, key, 0, &hash );
	if( !bucket )
	{
		return NULL;
	}

	int i = hashmapGetNode( map, hash, bucket, key );
	if( i == -1)
	{
		return NULL;
	}

	HashmapNode *node = DArray_get( bucket, i );
	check( node != NULL, "Failed to get node from bucket when it should exist.");

	return node->data;

error:
	return NULL;
}

int hashmapTraverse( Hashmap *map, hashmapTraverseCb traverseCb )
{
	int i = 0;
	int j = 0;
	int rc = 0;

	for( i = 0; i < DArray_count(map->buckets); i++)
	{
		DArray *bucket = DArray_get( map->buckets, i )	;
		if( bucket )
		{
			for( j = 0; j < DArray_count(bucket); j++)
			{
				HashmapNode *node = DArray_get( bucket, j );
				rc = traverseCb( node );
				if( rc != 0 )
				{
					return rc;
				}
			}
		}
	}
	return 0;
}

void* hashmapDelete( Hashmap *map, void *key)
{
	uint32_t hash = 0;
	DArray *bucket = hashmapFindBucket( map, key, 0, &hash );
	if( !bucket )
	{
		return NULL;
	}

	int i = hashmapGetNode( map, hash, bucket, key );
	if( i == -1 )
	{
		return NULL;
	}

	HashmapNode *node = DArray_get( bucket, i );
	void *data = node->data;
	free( node );

	HashmapNode *ending = DArray_pop( bucket );

	if( ending != node )
	{
		/* Alright looks like not the last one, swap it */
		DArray_set( bucket, i, ending );
	}

	return data;
}