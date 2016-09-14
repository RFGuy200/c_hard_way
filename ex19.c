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

void log_warn_test()
{
	log_warn("You can totally ignore this");
	log_warn("Maybe consider looking at %s", "/etc/passwrd");
}

void log_info_test()
{
	log_info("Well I did something mundane");
	log_info("It happenned %f times today", 1.3f);
}

int test_check(char *file_name)
{
	FILE *input = NULL;

	input = fopen(file_name, "r");
	check(input, "Failed to open file %s", file_name);
	fclose(input);
	return 0;

error:
	if(input) fclose(input);
	return -1;
}
	



int main( int argc, char *argv[])
{
	debug_test();
	errno = 2;
	log_error_test();
	log_warn_test();
	log_info_test();
	check(test_check("ex19.c") == 1, "failed with ex19.c");
	

	return 0;

error:
	return 1;

}
