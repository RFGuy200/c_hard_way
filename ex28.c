#include <stdio.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>



int glob_call(const char *exp, glob_t *globlist)
{
	int i = 0;

	globlist = malloc(sizeof(glob_t));
	
	int rc = glob(exp, GLOB_PERIOD, NULL, globlist);
	if (rc == GLOB_ERR || rc == GLOB_NOSPACE || rc == GLOB_ABORTED ||rc == GLOB_NOMATCH)
		exit(EXIT_FAILURE);


	for(i = 0; globlist->gl_pathv[i] != NULL; i++)
		printf("%s\n", globlist->gl_pathv[i]);

	return 0;
}



int main(int argc, char *argv[])
{
	glob_t *globlist;
	int i = 0;
	glob_call("*.c", globlist);

	for(i = 0; globlist->gl_pathv[i] != NULL; i++)
		printf("%s\n", globlist->gl_pathv[i]);



	return 0;
}
	
