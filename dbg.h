/* Use this file to all your programs in c. Tools to debug and to check */

#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifdef NDEBUG
#define debug(M,...) 
#else 
#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None":strerror(errno))

#define log_err(M,...) fprintf(stderr,\
	"[ERROR] (%s:%d: errno: %s)" M "\n", __FILE__, __LINE__, \
	clean_errno(), ##__VA_ARGS__)

#endif
