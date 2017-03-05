#include <stdio.h>

long long a[9999999] = {0};

int main( void ) {
	long long x = 0;
	while( scanf( "%lld", &x ) != -1 ) {
		long long sum = 0, n = -1, i = 0, j = 0;
		char c = '\0';
		while( c != '\n' && c != EOF )
			scanf( "%lld%c", &a[++n], &c );
		
		sum = a[0] * n;
		for( i = 1 ; i < n ; i++ )
			sum = sum * x + a[i] * ( n - i );
		
		printf( "%lld\n", sum );
	}
	
	return 0;
}
