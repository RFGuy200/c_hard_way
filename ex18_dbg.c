/*This is a program to learn about function pointers*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"



typedef int (*compare_cb)(int a, int b);

int* bubble_sort(int *numbers, int count, compare_cb comp)
{
	int i = 0;
	int j = 0;
	int temp = 0;

	int *target = malloc(sizeof(int) * count);
	mem_check(target);

	
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
error:
	exit(EXIT_FAILURE);
}

int sorted_order (int a, int b)
{
	return a - b;
}

int reversed_order(int a, int b)
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
	check(sorted, "Failed to sort");
	
	for(i = 0; i < count; i++){
		printf("%d", sorted[i]);
	}
	printf("\n");
	unsigned char *data = (unsigned char*) comp;
	for(i = 0; i< 25; i++){
		printf("%02x", data[i];
		if(i>19)
			data[i] = 1;
	}
	printf("\n");

	free(sorted);
error:
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	check(argc>2, "Need to give some arguments to sort, Usage ex.18 1 4 78 3 ");	
	int count = argc - 1;
	char **inputs = argv + 1;
	int i = 0;

	int *numbers = malloc(sizeof(int)*count);
	mem_check(numbers);
	for (i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}	

	test_sorted(numbers, count, sorted_order);
	test_sorted(numbers, count, reversed_order);
	test_sorted(numbers, count, strange_order);
	


	free(numbers);

	return 0;

error:
	return 1;
}

