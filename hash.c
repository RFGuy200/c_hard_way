#include <stdio.h>
#include <bstrlib.h>

unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;
	int i = 0;

	while ((c = *str++)) 
	{
		hash = ((hash << 5) + hash) + c; // hash*33 + c
	}

  return hash;
}

unsigned long hashXor(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++)) 
	{
		hash = hash * 33 ^ c; // hash*33 + c
	}

  return hash;
}

int main(int argc, char const *argv[])
{
	unsigned char myString[100] = "string";

	printf( "XOR hash = %li\n", hashXor(myString) );
	printf( "hash = %li\n", hash(myString) );

	bstring longString = bfromcstr( "First Second Third");
	//bstrList strList = bsplit( longString, ' ');

	return 0;
}