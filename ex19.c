/* exercise to learn about debug macros and lear how to use them */

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

void debug_test()
{
	debug(" I have brown hair");
	debug(" I am %d years old", 37);
}

void log_error_test()
{
	log_err("I believe everything is broken");
}


int main( int argc, char *argv[])
{
	debug_test();
	errno = 1;
	log_error_test();
	

	return 0;
}
