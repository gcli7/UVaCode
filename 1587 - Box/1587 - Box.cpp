#include <stdio.h>
#include <stdlib.h>

int main( void ) {
	int input[6][2] = {0}, temp = 0, i = 0, j = 0;
	
	while( scanf( "%d", &input[0][0] ) != -1 ) {
		scanf( "%d", &input[0][1] );
		if( input[0][0] > input[0][1] ) {
			temp = input[0][0];
			input[0][0] = input[0][1];
			input[0][1] = temp;
		}
		
		for( i = 1 ; i < 6 ; i++ ) {
			scanf( "%d %d", &input[i][0], &input[i][1] );
			if( input[i][0] > input[i][1] ) {
				temp = input[i][0];
				input[i][0] = input[i][1];
				input[i][1] = temp;
			}
		}
		
		for( i = 5 ; i > 0 ; i-- )
			for( j = 0 ; j < i ; j++ )
				if( ( input[j][0] > input[j+1][0] ) || ( ( input[j][0] == input[j+1][0] ) && ( input[j][1] > input[j+1][1] ) ) ) {
					temp = input[j][0];
					input[j][0] = input[j+1][0];
					input[j+1][0] = temp;
					
					temp = input[j][1];
					input[j][1] = input[j+1][1];
					input[j+1][1] = temp;
				}
		
		int flag = 1;		
		for( i = 1 ; i < 4 ; i++ )
			if( input[i-1][0] != input[i][0] ) {
				flag = 0;
				break;
			}
		if( input[4][0] != input[5][0] )
				flag = 0;
		if( input[0][1] != input[1][1] )
				flag = 0;
		if( input[0][1] != input[4][0] )
				flag = 0;
		if( flag == 1 ) {
			for( i = 3 ; i < 6 ; i++ )
				if( input[i-1][1] != input[i][1] ) {
					flag = 0;
					break;
				}
		}
		
		if( flag )
			printf( "POSSIBLE\n" );
		else
			printf( "IMPOSSIBLE\n" );
	}
	
	return 0;
}
