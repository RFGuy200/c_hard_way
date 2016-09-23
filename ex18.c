/*This is a program to learn about function pointers*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>



void die(const char *message)
{
	if(errno){
		perror("ERROR");
	}else{
		printf("ERROR: %s\n", message);
	}
	exit(10);
}	

typedef int (*compare_cb)(int a, int b);

int* bubble_sort(int *numbers, int count, compare_cb comp)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	int *target = malloc(sizeof(int) * count);

	if(!target)
		die("Memory error");

	memcpy(target,numbers, count * sizeof(int));

	for(i = 0; i < count; i++){
		for(j = 0; j < count -1; j++){
			if(comp(target[j], target [j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp; 
			}
		}
	}
	return target;
}

int sorted_order (int a, int b)
{
	return a - b;
}

int reversed_order(int a, int )
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0){
		return	0;
	}else{
		return a % b;
	}
}

void test_sorted(int *number, int count, compare_cb comp)
{
	int i = 0;	
	int *sorted = bubble_sort(number, count, comp);
	if(!sorted)
		die("Failed to sort!");
	
	for(i = 0; i < count; i++){
		printf("%d", sorted[i]);
	}
	printf("\n");
	unsigned char *data = (unsigned char*) comp;
	for(i = 0; i< 25; i++){
		printf("%02x", data[i]);
	}
	printf("\n");

	free(sorted);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		die("Need to give some arguments. Usage: ex18 4 3 1 5 6");
	
	int count = argc - 1;
	char **inputs = argv + 1;
	int i = 0;

	int *numbers = malloc(sizeof(int)*count);
		if(!numbers)
			die("Memory error");

	for (i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}	

	test_sorted(numbers, count, sorted_order);
	test_sorted(numbers, count, reversed_order);
	test_sorted(numbers, count, strange_order);
	


	free(numbers);

	return 0;
}

