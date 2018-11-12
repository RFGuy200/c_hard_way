#include <stdio.h>
#include <stdint.h>

typedef union testUnion
{
	struct testStruct
	{
		unsigned char one :1;
		unsigned char two :1;
		unsigned char three :1;
		unsigned char four :1;
		unsigned char five :1;
		unsigned char six :1;
		unsigned char seven :1;
		unsigned char eight :1;
		unsigned char nine :1;
		unsigned char ten :1;
		unsigned char eleven :1;
		unsigned char twelve :1;
		unsigned char thirteen :1;
		unsigned char fourteen :1;
		unsigned char fifteen :1;
		unsigned char sixteen :1;
	}testStruct;
	short int testByte;
}testUnion;

int main(int argc, char const *argv[])
{
	int testVar = 0;
	testUnion test = {.testByte = 0x3210};

	testVar |= test.testStruct.one;
	printf("bit one = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.two;
	printf("bit two = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.three;
	printf("bit three = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.four;
	printf("bit four = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.five;
	printf("bit five = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.six;
	printf("bit six = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.seven;
	printf("bit seven = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.eight;
	printf("bit eight = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.nine;
	printf("bit nine = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.ten;
	printf("bit ten = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.eleven;
	printf("bit eleven = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.twelve;
	printf("bit twelve = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.thirteen;
	printf("bit thirteen = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.fourteen;
	printf("bit fourteen = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.fifteen;
	printf("bit fifteen = %i\n", testVar);
	testVar = 0;
	testVar |= test.testStruct.sixteen;
	printf("bit sixteen = %i\n", testVar);
	testVar = 0;

	return 0;
}