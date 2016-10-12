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

void match(glob_t *globlist, const char *string)
{
	int i = 0;
	char line[1000];
	FILE *fp = NULL;
	
	for(i = 0; globlist->gl_pathv[i] != NULL; i++){
		fp = fopen(globlist->gl_pathv[i], "r");

		while(fscanf(fp, "%999[^\n]\n", line) == 1){
			if(strstr(line, string)){
				printf("%s\n", globlist->gl_pathv[i]);
				break;
			}
		}
		fclose(fp);	
	}				
}




int main(int argc, char *argv[])
{
	int i = 0;
	glob_t *globlist;



	globlist = list_create( "*.c");
	match(globlist, argv[1]);

	
	
/*	for(i = 0; globlist->gl_pathv[i] != NULL; i++)
		printf("%s\n", globlist->gl_pathv[i]);*/

	free(globlist);

	return 0;
}

