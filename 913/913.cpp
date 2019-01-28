#include <stdio.h>

int main( void )
{
	unsigned long long input = 0;
	while( scanf( "%lld", &input ) != -1 ) {
		unsigned long long nextLine = 0, temp = 0;
		input++;
		
		temp = 2 + ( input / 2 - 1 ) * 4;
		nextLine = ( 2 + temp ) * ( input / 2 ) / 2 + 1;
		printf( "%lld\n", ( nextLine - 4 ) * 3 );
	}
	
	return 0;
}
