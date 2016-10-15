#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include "dbg.h"

glob_t* list_create(const char *exp) //function creates glob list with search parameters defined in main
{
	glob_t *pnt = malloc(sizeof(glob_t));
	check_mem(pnt);

	int rc = glob(exp, GLOB_BRACE | GLOB_TILDE, NULL, pnt);	
	check(rc !=  GLOB_ABORTED || GLOB_NOSPACE || GLOB_ERR, "Glob function failed");
	check(rc != GLOB_NOMATCH, "There are no *.c or *.h files in this directory");
	
	return pnt;
error:
	exit(EXIT_FAILURE);
}

void match(glob_t *globlist, int argc, char *string[]) //function checks if ALL search parameters are met
{
	int i = 0;
	int j = 0;
	char line[1000];
	FILE *fp = NULL;
	int match = 0;
	int match_all = 0;
	int match_num = 0;
	
		for(i = 0; globlist->gl_pathv[i] != NULL; i++){
			fp = fopen(globlist->gl_pathv[i], "r");
			check(fp != NULL,"Failed to open the file");

			match_all = 0;
			
			for(j = 1; j < argc; j++){

				match = 0;


				while(fgets(line, 999, fp) != NULL){
					if(strstr(line, string[j])){
						match = 1;
						match_num++;
						break;
					}
				} 
				if(match == 0) break;
				else match_all++;
			}

			if(match_all == argc-1)
				printf("%s\n", globlist->gl_pathv[i]);

			fclose(fp);
		}	
		if(match_num == 0) printf("No match found\n");
error:
	exit(EXIT_FAILURE);

}

void match_or(glob_t *globlist, int argc, char *string[])  //function checks if ANY of search parameters are met
{
	int i = 0;
	int j = 0;
	char line[1000];
	FILE *fp = NULL;
	int match = 0;
	
		for(i = 0; globlist->gl_pathv[i] != NULL; i++){
			fp = fopen(globlist->gl_pathv[i], "r");
			check(fp != NULL, "Failed to open the file");

			for(j = 2; j < argc; j++){

				while(fgets(line, 999, fp) != NULL){
					if(strstr(line, string[j])){
						printf("%s\n", globlist->gl_pathv[i]);
						match = 1;
						break;
					}
				} 
				if(match == 1) break;
				
			}	
			fclose(fp);
		}	
error:
	exit(EXIT_FAILURE);

}



int main(int argc, char *argv[])
{
	glob_t *globlist;

	check(!(argc < 2 || ((strstr(argv[1], "-o")) && argc<3)),\
		 "Need at least one search parameter\n");
	
	globlist = list_create( "{~/workspace/c_hard_way/*.c,~/workspace/c_hard_way/*.h}");
	if(strstr(argv[1], "-o")){
		match_or(globlist, argc, argv);
	}else{ match(globlist, argc, argv); }
	
	free(globlist);

	return 0;
error:
	return 1;
}

