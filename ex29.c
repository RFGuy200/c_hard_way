#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function) (const char *data)

int main(int argc, char *argv[])
{
	int rc = 0;
	check(argc == 4, "USAGE: ex29 libex29.so function data");

	char lib_file = argv[1];
	char func_to_run = argv[2];
	char data = argv[3];

	void *lib = dlopen(lib_file, RTDL_NOW);
	check(lib != NULL, "Failed to open the library %s: %s\n", lib_file, dlerror());

	lib_func = dlsym(lib, func_to_run);
	check(lib_func != NULL, "Did not find function %s in the library %s: %s\n", func_to_run, lib_file, dlerror());

	rc = func(data);
	check(rc != 0, "Function %s returned %d for data:%s\n", func_to_run, rc, data);

	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s\n", lib_file);

	return 0;
error:
	return 1;
}
