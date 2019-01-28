#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) {
	int cases = 0, t = 0;
	scanf( "%d", &cases );
	getchar();
	while( ++t <= cases ) {
		long matrix[10005] = {0}, N = 0, flag = 0, i = 0, j = 0;
		
		for( i = 0 ; i < 4 ; i++ )
			getchar();
			
		scanf( "%ld", &N );
		N = N * N;
		
		for( i = 0 ; i < N ; i++ ) {
			scanf( "%ld", &matrix[i] );
			if( matrix[i] < 0 )
				flag = 1;
		}
		if( flag ) {
			printf( "Test #%d: Non-symmetric.\n", t );
			continue;
		}
		
		for( i = 0, j = N - 1 ; i <= j ; i++, j-- )
			if( matrix[i] != matrix[j] ) {
				printf( "Test #%d: Non-symmetric.\n", t );
				break;
			}
		if( i > j )
			printf( "Test #%d: Symmetric.\n", t );
	}
	
	return 0;
}
