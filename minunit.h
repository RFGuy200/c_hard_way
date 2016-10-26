#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <dbg.h>
#include <stdlib.h>

#define mu_suite_start() char* message=NULL

#define mu_assert(test,message) if(!(test)) {log_err(message);return message;}

#define mu_run_test(test) debug("\n--------%s", " " #test);message=test();test_run++;if(message) return message;
