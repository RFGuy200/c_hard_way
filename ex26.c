#include <stdio.h>
#include <glob.h>
#include <stdlib.h>
#include "dbg.h"
#include <assert.h>

int findlog(glob_t **log_list)
{
	*log_list = malloc(sizeof(glob_t));
	check_mem(*log_list);
	
	int rc = glob("/var/log/*.log", GLOB_PERIOD, NULL, *log_list);
	check(rc != GLOB_NOMATCH, "No match found");
	check(rc != GLOB_NOSPACE || rc != GLOB_ABORTED, "Glob function error");

	return 0;

error:
	return -1;	
}

void search_logs(int argc, char *argv[], glob_t **logfilesi, int *match_number)
{
	assert(argc > 1 && "Need at least one search parameter");
	

}

int main (int argc, char *argv[])
{

	glob_t *logfiles = NULL;
	int match_number = 0;

	findlog(&logfiles);

	search_logs(argc, argv, &logfiles, &match_number);

	if(match_number == 0){
			printf("No match found\n");
	}else{
		printf("Total number of matches: %d\n", match_number);	
	}
	



	free(logfiles);
	
	return 0;
}

