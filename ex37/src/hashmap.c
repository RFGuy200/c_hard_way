#undef NDEBUG
#include <hashmap.h>
#include <stdio.h>
#include <bstrlib.h>
#include <dbg.h>

static int default_compare(void *a, void *b)
{
	return bstrcmp((bstring) a, (bstring) b);
}

static uint32_t default_hash(void *a)
{
	size_t len = blength((bstring) a);
	char *key = bdata((bstring) a);
	uint32_t hash  = 0;
	uint32_t i = 0;

	for(hash = i = 0; i < len; ++i){
		hash +=key[i];
		hash += (hash << 10);
		hash +=(hash >> 6);
	}

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
}

Hashmap* Hashmap_create(Hashmap_compare compare, Hashmap_hash hash)
{
	Hashmap *map = calloc(1, sizeof(Hashmap));
	check_mem(map);

	map->compare = compare == NULL?default_compare:compare;	
	map->hash = hash == NULL?default_hash:hash;
	map->buckets = Darray_create(sizeof(Darray*), DEFAULT_NUMBER_OF_BUCKETS); 

	map->buckets->end = map->buckets->max;
	check_mem(map->buckets);

	return map;
error:
	if(map)
		Hashmap_destroy(map);
	
}

void Hashmap_destroy(Hashmap map)
{
	int i = 0;
	int j = 0;

	if(map){
		if(map->buckets){
			for(i = 0; i < Darray_count(map->buckets); i++){
				Darray *bucket = Darray_get(map->buckets, i);
				
				if(bucket){
					for(j = 0; j < Darray_count(bucket);j++)
						free(Darray_get(bucket, j));
						Darray_destroy(bucket);
				}
			}
		}
		free(map);
	}
}

