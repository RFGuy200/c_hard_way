#include <stdio.h>

int main( int argc, char *argv[])
{
	int a = 179;
	int b = 10;
	int c = 100;

	printf("mod: %d\n", a%c);
	printf("division: %d\n", (a%c)/b);

return 0;
}
