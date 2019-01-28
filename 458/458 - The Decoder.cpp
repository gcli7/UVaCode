#include <stdio.h>

int main( void )
{
	char input = '\0';
	
	while( scanf( "%c", &input ) != EOF ) {
		if( input == '\n' )
			printf("\n");
		else
			printf( "%c", input-7 );
	}
	
	return 0;
}
