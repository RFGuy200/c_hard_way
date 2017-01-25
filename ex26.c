#include <stdio.h>
#include <glob.h>
#include <stdlib.h>
#include "dbg.h"
#include <assert.h>
#include <string.h>

int findlog(glob_t **log_list)
{
	*log_list = malloc(sizeof(glob_t));
	check_mem(*log_list);
	
	int rc = glob("/var/log/*.log", GLOB_PERIOD, NULL, *log_list);
	check(rc != GLOB_NOMATCH, "No log files found");
	check(rc != GLOB_NOSPACE || rc != GLOB_ABORTED, "Glob function error");

	return 0;

error:
	return -1;	
}


void search_logs_and(int argc, char *argv[], glob_t *logfiles)
{
	assert(argc > 1 && "Need at least one search parameter");

	int i = 0;
	int n = 0;
	int file_counter = logfiles->gl_pathc;
	char **file_list = logfiles->gl_pathv;
	char line[1000];
	int match = 0;
	int file_match = 0;
	
	for( i = 0; i < file_counter; i++){
		FILE *in = fopen(file_list[i], "r");
		assert(in != NULL && "Failed to open the file");
	
			for( n = 1; n < argc; n++){
				while(!feof(in)){
					fgets(line, 999, in);
					if(strstr(line, argv[n])){
						match++;
						rewind(in);
						break;
					}
				}
			}
		if(match == argc - 1){
			printf("%s\n", file_list[i]);
			file_match++;
		}
		match = 0;
		fclose(in);
	}
	if(file_match == 0)
			printf("No files found with these search parameters\n");		

}

void search_logs_or(int argc, char *argv[], glob_t *logfiles)
{
	assert(argc > 1 && "Need at least one search parameter");

	int i = 0;
	int n = 0;
	int file_counter = logfiles->gl_pathc;
	char **file_list = logfiles->gl_pathv;
	char line[1000];
	int match = 0;
	int file_match = 0;
	
	for( i = 0; i < file_counter; i++){
		FILE *in = fopen(file_list[i], "r");
		assert(in != NULL && "Failed to open the file");

			for( n = 2; n < argc && match == 0; n++){
				while(!feof(in)){
					fgets(line, 999, in);
					if(strstr(line, argv[n])){
						match++;
						break;
					}
				}
			}
		if(match > 0){
			printf("%s\n", file_list[i]);
			file_match++;
		}
		match = 0;
		fclose(in);
	}
	if(file_match == 0)
			printf("No files found with these search parameters\n");		

}

int main (int argc, char *argv[])
{

	glob_t *logfiles = NULL;

	findlog(&logfiles);
	
	if(strstr(argv[1], "-o") && strlen(argv[1]) == 2){
		search_logs_or(argc, argv, logfiles);
	}else{
		search_logs_and(argc, argv, logfiles);
	}

	free(logfiles);
	
	return 0;
}

