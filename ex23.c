#include <stdio.h>
#include <string.h>
#include "dbg.h"

int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count+7)/8;
		log_info("value of n  inside duffs_device: %d", n);
		log_info("coutn%8 value: %d", (count%8));
		switch (count%8){
			case 0:
				do{
					*to++ = *from++;
					printf("case 0\n");
				case 7:
					*to++ = *from++;
					printf("case 7\n");
				case 6:
					*to++ = *from++;
					printf("case 6\n");
				case 5:
					*to++ = *from++;
					printf("case 5\n");
				case 4:
					*to++ = *from++;
					printf("case 4\n");
				case 3:
					*to++ = *from++;
					printf("case 3\n");
				case 2:
					*to++ = *from++;
					printf("case 2\n");
				case 1:
					*to++ = *from++;
					printf("case 1\n");
				}while(--n>0);
		}
	}
	return count;
}








int main(int argc, char *argv[])
{
	int n = 0;
	char pointer_from[30] = {'x'};
	char pointer_to[30] = {'y'};
	memset(pointer_from, 'x', 30);
	memset(pointer_to, 'y', 30);
	


		printf("%s\n", pointer_to);


	duffs_device(pointer_from, pointer_to, 17);




		printf("%s\n", pointer_to);

	

	return 0;
}
