#include <stdio.h>

long long f91( long long n )
{
	if( n <= 100 )
		return f91( f91( n + 11 ) );
	else
		return n - 10;
}

int main( void )
{
	long long input = 0;

	while( scanf( "%lld", &input ) !=EOF && input )
		printf( "f91(%lld) = %lld\n", input, f91( input ) );
	
	return 0;
}
