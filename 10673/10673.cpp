#include<stdio.h>

int main()
{
	long long cases = 0;
	scanf( "%lld", &cases );
	while( cases-- ) {
		double x = 0, k = 0;
		long a = 0, b = 0, sum = 0, p = 0, q = 0;
		
		scanf( "%lf %lf", &x, &k );
		if( ( x / k ) - ( int )( x / k ) != 0 ) {
			a = x / k;
			b = ( x / k ) + 1;
		}
		else {
			a = x / k;
			b = a;
		}

		for( p = 0 ; ; p++ ) {
			sum = 0;
			for( q = 0 ; sum < x ; q++ )
				sum = p * a + q * b;
				
			if( sum == x ) {
				q--;
				break;
			}
		}
		
		printf( "%ld %ld\n", p, q );
	}
	
	return 0;
}
