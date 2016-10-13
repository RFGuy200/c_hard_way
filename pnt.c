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

void match(glob_t *globlist, int argc, char *string[])
{
	int i = 0;
	int j = 0;
	char line[1000];
	FILE *fp = NULL;
	int match = 0;
	int match_all = 0;
	
		for(i = 0; globlist->gl_pathv[i] != NULL; i++){
			fp = fopen(globlist->gl_pathv[i], "r");

			match_all = 0;
			
			for(j = 1; j < argc; j++){

				match = 0;


				while(fscanf(fp, "%999[^\n]\n", line) == 1){
					if(strstr(line, string[j])){
						match = 1;
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

}

void match_or(glob_t *globlist, int argc, char *string[])
{
	int i = 0;
	int j = 0;
	char line[1000];
	FILE *fp = NULL;
	int match = 0;
	
		for(i = 0; globlist->gl_pathv[i] != NULL; i++){
			fp = fopen(globlist->gl_pathv[i], "r");

			for(j = 2; j < argc; j++){

				while(fscanf(fp, "%999[^\n]\n", line) == 1){
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

}



int main(int argc, char *argv[])
{
	glob_t *globlist;


	if(argc < 2 || ((strstr(argv[1], "-o")) && argc<3)) {
		printf("ERROR: need at least one search parameter\n");
		return 1;
	}
		
	globlist = list_create( "*.c");
	if(strstr(argv[1], "-o")){
		match_or(globlist, argc, argv);
	}else{ match(globlist, argc, argv); }
	
	free(globlist);

	return 0;
}

