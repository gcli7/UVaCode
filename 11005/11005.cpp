#include <stdio.h>

int main( int argc, char *argv[] ) {
	int cases = 0, t = 0;
	scanf( "%d", &cases );
	while( ++t <= cases ) {
		if( t > 1 )
			printf( "\n" );
		printf( "Case %d:\n", t );
		
		int base[40] = {0}, i = 0;
		
		for( i = 0 ; i < 36 ; i++ )
			scanf( "%d", &base[i] );
			
		int quantity = 0;
		scanf( "%d", &quantity );
		while( quantity-- ) {
			long long number = 0, baseNumber[40] = {0}, index = 0, cost = 0, temp = 0, sum = 0;
			
			scanf( "%lld", &number );
			for( i = 2 ; i <= 36 ; i++ ) {
				temp = number;
				sum = 0;
				while( temp ) {
					sum += base[temp % i];
					temp /= i;
				}
				if( sum < cost ) {
					for( ; index > 0 ; index-- )
						baseNumber[index] = 0;
					baseNumber[index++] = i;
					cost = sum;
				}
				else if( sum == cost || cost == 0 ) {
					baseNumber[index++] = i;
					cost = sum;
				}
			}
			
			printf( "Cheapest base(s) for number %lld:", number );
			for( i = 0 ; i < index ; i++ )
				printf( " %lld", baseNumber[i] );
			printf( "\n" );
		}
	}
	
	return 0;
}
