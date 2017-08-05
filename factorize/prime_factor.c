#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
	int array[10] = {0};
	int test = 2;
	int i = 0;
	int index = 0;
	int number = 100;  //number to factorize
	int not_prime = 0;

	assert(number > 0 && "Number must be greater than 1");
	
	while(number != 1){
		if(number % test == 0){		
				for(i = 2; i < test; i++){
					if(test % i == 0){
						not_prime = 1;
						break;
					}
				}
			if(not_prime == 0){
				array[index] = test;
				index++;	
				number /=test;
				test = 2;
			}
			not_prime = 0;
		}else{
			test++;
		}
	}
	
	i = 0;
	printf("[ ");

	while(array[i] != 0){
		printf("%d ", array[i]);
		i++;
	}

	printf("]\n");

	return 0;

}		

