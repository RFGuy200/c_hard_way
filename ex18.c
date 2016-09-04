/*This is a program to learn about function pointers*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>



void die(const char *message)
{
	if(errno){
		perror("ERROR");
	}esle{
		printf("ERROR: %s\n", message);
	}
	exit(10);
}	

typedef int (*compare_cb)(int a, int b);
