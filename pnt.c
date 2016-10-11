#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>

glob_t* pnt_create(const char *exp)
{
	glob_t *pnt = malloc(sizeof(glob_t));

	glob(exp, GLOB_PERIOD, NULL, pnt);	

	return pnt;
}


int main(int argc, char *argv[])
{
	int i = 0;
	glob_t *globlist;
	globlist = pnt_create( "*.c");

	for(i = 0; globlist->gl_pathv[i] != NULL; i++)
	printf("%s\n", globlist->gl_pathv[i]);
	free(globlist);

	return 0;
}

