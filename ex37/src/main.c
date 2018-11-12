
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main( int argc, char const *argv[] )
{
	char fileToOpen[20] = "";

	printf( "%s\n", strerror(errno) );	
	scanf( "%s", fileToOpen );

	FILE* in = fopen( fileToOpen, "r" );
	printf( "%s\n", strerror(errno) );	

	if( !in ) 
	{
		printf( "%s\n", strerror(errno) );	
		return -1;
	}
	else
	{
		printf( "No problem\n" );
		fclose( in );
	}

	return 0;
}