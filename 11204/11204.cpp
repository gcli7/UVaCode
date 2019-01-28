#include<stdio.h>

int main()
{
	long long cases = 0;
	scanf( "%lld", &cases );
	while( cases-- ) {
		int base[35][35] = {0};
		int instruments = 0, students = 0, i = 0, j = 0;
		
		scanf( "%d %d", &instruments, &students );
		for( i = 0 ; i < students ; i++ )
			for( j = 0 ; j < instruments ; j++ )
				scanf( "%d", &base[i][j] );
		
		int counter = 0, output = 1;
		for( i = 0 ; i < instruments ; i++ ) {
			counter = 0;
			for( j = 0 ; j < students ; j++ ) {
				if( base[j][i] == 1 )
					counter++;
			}
			if( counter >= 2 )
				output *= counter;
		}
		
		printf( "%d\n", output );
	}
	
	return 0;
}
