#include "minunit.h"
#include <stdint.h>
#include <hashmap.h>
#include <assert.h>
#include <bstrlib.h>

Hashmap *map = NULL;
static int traverseCalled = 0;
struct tagbstring test1 = bsStatic( "test data 1" );
struct tagbstring test2 = bsStatic( "test data 2" );
struct tagbstring test3 = bsStatic( "test data 3" );
struct tagbstring expect1 = bsStatic( "THE VALUE 1" );
struct tagbstring expect2 = bsStatic( "THE VALUE 2" );
struct tagbstring expect3 = bsStatic( "THE VALUE 3" );

static int traverseGoodCb( HashmapNode *node )
{
	debug( "KEY: %s", bdata((bstring) node->key));
	traverseCalled++;

	return 0;
}

static int traverseFailCb( HashmapNode *node )
{
	debug( "KEY: %s", bdata((bstring) node->key));
	traverseCalled++;

	if(traverseCalled == 2)	
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char* testCreate()
{
	map = hashmapCreate( NULL, NULL );
	mu_assert( map != NULL, "Failed to create map.");

	return NULL;
}

char* testDestroy()
{
	hashmapDestroy( map );

	return NULL;
}

char* testGetSet()
{
	int rc = hashmapSet( map, &test1, &expect1 );
	mu_assert( rc == 0, "Failed to set test1." );
	bstring result = hashmapGet( map, &test1 );
	mu_assert( result == &expect1, "Wrong value for test1." );

	rc = hashmapSet( map, &test2, &expect2 );
	mu_assert( rc == 0, "Failed to set test2." );
	result = hashmapGet( map, &test2 );
	mu_assert( result == &expect2, "Wrong value for test2." );

	rc = hashmapSet( map, &test3, &expect3);
	mu_assert( rc == 0, "Failed to set test3." );
	result = hashmapGet( map, &test3 );
	mu_assert( result == &expect3, "Wrong value for test3.");

	return NULL;
}

char* testTraverse()
{
	int rc = 0;
	traverseCalled = 0;
	rc = hashmapTraverse( map, traverseGoodCb );
	mu_assert( rc == 0, "Failed to traverse." );
	mu_assert( traverseCalled == 3, "Wrong count traverse for fail.");

	traverseCalled = 0;
	rc = hashmapTraverse( map, traverseFailCb );
	mu_assert( rc == 1, "Failed to traverse." );
	mu_assert( traverseCalled == 2, "Wrong count traverse for fail." );

	return NULL;
}

char* testDelete()
{
	bstring deleted = (bstring)hashmapDelete( map, &test1 );
	mu_assert( deleted != NULL, "Got NULL on delete." );
	mu_assert( deleted == &expect1, "Should be test1" );
	bstring result = hashmapGet( map, &test1 );
	mu_assert( result == NULL, "Should delete" );

	deleted = (bstring)hashmapDelete( map, &test2 );
	mu_assert( deleted != NULL, "Got NULL on delete." );
	mu_assert( deleted == &expect2, "Should get test2." );
	result = hashmapGet( map, &test2 );
	mu_assert( result == NULL, "Should delete." );

	deleted = (bstring)hashmapDelete( map, &test3 );
	mu_assert( deleted != NULL, "Got NULL on delete." );
	mu_assert( deleted == &expect3, "Should get test3." );
	result = hashmapGet( map, &test3 );
	mu_assert( result == NULL, "Should delete." );

	return NULL;
}

char *all_tests()

{	mu_suite_start();

	mu_run_test( testCreate );
	mu_run_test( testGetSet );
	mu_run_test( testTraverse );
	mu_run_test( testDelete );

		
	return NULL;
}

RUN_TESTS(all_tests);


