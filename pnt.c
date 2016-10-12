#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>

glob_t* list_create(const char *exp)
{
	glob_t *pnt = malloc(sizeof(glob_t));

	glob(exp, GLOB_PERIOD, NULL, pnt);	

	return pnt;
}

void match(glob_t globlist)
{
	for(i = 0; globlist->gl_pathv[i] != NULL; i++){
		fp = fopen(globlist->gl_pathv[i], "r");
			while(fscanf(fp, "%999[^\n]\n", line) == 1){
				
			
					
		fclose(fp);
	}



int main(int argc, char *argv[])
{
	int i = 0;
	glob_t *globlist;
	FILE *fp = NULL;
	char line[1000];


	globlist = list_create( "*.c");
	match(globlist);

	
	
/*	for(i = 0; globlist->gl_pathv[i] != NULL; i++)
		printf("%s\n", globlist->gl_pathv[i]);*/

	free(globlist);

	return 0;
}

