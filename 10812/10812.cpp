#include <stdio.h>

int main( int argc, char *argv[] ) {
	long long cases = 0;
	scanf( "%lld", &cases );
	while( cases-- ) {
		long long s = 0, a = 0;
		
		scanf( "%lld %lld", &s, &a );
		if( ( ( s % 2 ) && ( a % 2 ) || !( s % 2 ) && !( a % 2 ) ) && s >= a ) {
			printf( "%lld %lld\n", ( s - a ) / 2 + a, ( s - a ) / 2 );
		}
		else
			printf( "impossible\n" );
	}
	
	return 0;
}
