#include <stdio.h>

#define N 1299750

int prime[N] = {0};

int main( void ) {
	prime[0] = 1;
	prime[1] = 1;
	long i = 0, k = 0, j = 0;
	for( i = 2 ; i * i < N ; i++ )
		if( prime[i] == 0 )
			for( k = ( N - 1 ) / i, j = i * k ; k >= i ; j -= i, k-- )
				if( prime[k] == 0 )
					prime[j] = 1;

	long number = 0;
	while( scanf( "%ld", &number ) != -1 && number != 0 ) {
		int counter = 0;
		for( i = number ; prime[i] == 1 ; i-- )
			counter++;
		for( i = number ; prime[i] == 1 ; i++ )
			counter++;
  		printf( "%d\n", counter );
	}

	return 0;
}
