#include <stdio.h>

int main( void ) {
	long long base[500] = {0};	base[0] = 0;	base[1] = 1;
	int index = 0;
	for( index = 2 ; base[index-1] <= 100000000 ; index++ )
		base[index] = base[index-1] + base[index-2];
	index -= 2;	
	
	long long cases = 0;
	scanf( "%lld", &cases );
	while( cases-- ) {
		int output[500] = {0}, i = 0;
		long long input = 0;
		scanf( "%lld", &input );
		printf( "%lld = ", input );
		
		for( i = index ; input > 0 ; i-- )
			if( input >= base[i] ) {
				input -= base[i];
				output[i] = 1;
			}

		for( i = index ; output[i] == 0 ; i-- );
		for( ; i > 1 ; i-- )
			printf( "%d", output[i] );
		printf( " (fib)\n" );
	}
	
	return 0;
}
