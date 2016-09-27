#include <stdio.h>

int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count+7)/8;
		switch (count%8){
			case 0:
				do{
					*to++ = *from++;
				case 7:
					*to++ = *from++;
				case 6:
					*to++ = *from++;
				case 5:
					*to++ = *from++;
				case 4:
					*to++ = *from++;
				case 3:
					*to++ = *from++;
				case 2:
					*to++ = *from++;
				case 1:
					*to++ = *from++;
				}while(--n>0);
		}
	}
	return 0;
}








int main(int argc, char *argv[])
{
	int n = 10;
	int *pointer = (int[]){1,9,2,8,3,7,4,6,5};
	
	while(--n>0){
		printf("%d\n", *pointer++);
	}
	return 0;
}
