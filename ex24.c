#include <stdio.h>
#include "dbg.h"
#include <string.h>

#define MAX_DATA 100

typedef enum EyeColor {BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES} EyeColor;

const char *EYE_COLOR_NAMES[] = {"Blue", "Green", "Brown", "Black", "Other"};

typedef struct person{
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;

void remove_newline(char *name)
{
	char *n  = strchr(name, '\n');
	*n = '\0';
}

void remove_space(char *name)
{
	char *space = NULL;
	char *next = NULL;
	while(1){
		space = strchr(name, ' ');
		if(space == NULL)
			break;
		else{
			 do{
			next  = space;
			space++;
			*next = *space;
			} while(*space != '\0');
			 	
		}
	}
}
			

int main(int argc, char *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;

	printf("What is your first name?\n");
	in = fgets(you.first_name, MAX_DATA-1, stdin);
	check(in !=NULL, "Failed to read the first name");
	remove_newline(you.first_name);
	remove_space(you.first_name);
	
	printf("What is your last name?\n");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in !=NULL, "Failed to read the last name");
	remove_newline(you.last_name);
	remove_space(you.last_name);


	printf("How old are you?\n");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc>0, "You have to enter a number");

	printf("What color are your eyes:\n");
	for (i=0; i<= OTHER_EYES; i++){
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	
	printf("> ");

	int eye = -1;
	rc = fscanf(stdin, "%d", &eye);
	check(rc>0, "You have to enter a number\n");

	you.eyes = eye - 1;
	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option\n");
	
	printf("How much do you make an hour?\n");
	rc = fscanf(stdin, "%f", &you.income);
	check(rc>0, "Enter floating point number");

	printf("--------Results--------\n");
	printf("First Name: %s\n", you.first_name);
	printf("Last Name: %s\n", you.last_name);
	printf("Your age: %d\n", you.age);
	printf("Your eye color: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Your income is: %f\n", you.income);





	return 0;
error:
	return -1;
}


	
				
