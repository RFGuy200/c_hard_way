#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include "dbg.h"
#include <stdlib.h>

#define MU_SUITE_START() char* message=NULL

#define MU_ASSERT(test,message) if(!(test)) {log_err(message); return message;}

#define MU_RUN_TEST(test) debug("\n--------%s---------", #test); message=test(); tests_run++; if(message) return message;

#define RUN_TESTS(name) int main(int __attribute__((unused)) argc, char *argv[]){\
	argc = 1;\
	debug("\n--------Running: %s", argv[0]);\
	printf("--------------------\nRunning: %s\n", argv[0]);\
	char* result = name();\
	if (result != 0){\
		printf("FAILED: %s\n", result);\
	}\
	else {\
		printf("ALL TESTS PASSED\n");\
	}\
	printf("Tests run: %d\n", tests_run);\
	exit(result != 0);\
}
	int tests_run;

#endif
