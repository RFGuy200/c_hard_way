#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dbg.h"

int safercopy(int from_len, char* from, int to_len, char* to)
{
	
	int i = 0;
	assert(from != NULL && to != NULL && "To or from can't be NULL");

	int max = to_len - 1 > from_len ? from_len : to_len;

	if(from_len < 1 || to_len <= 1) 
		return -1;

	for( i = 0; i<max ; i++)
		from[i] = to[i];

	to[to_len -1] = '\0';

	return i;
}


int main (int argc, char *argv[])
{
	char from[] = "01234567";
	int from_len = sizeof(from);

	char to[] = "012345";
	int to_len = sizeof(to);

	debug("Copying %s:%d to %s:%d\n", from, from_len, to, to_len);

	int rc = safercopy(from_len, from, to_len, to);	
	check(rc > 0, "Copy failed");
	check(to[to_len - 1] == '\0', "String not terminated");

	debug("Result is %s:%d", to, to_len);

	return 0;
error: 
	return 1;
}
