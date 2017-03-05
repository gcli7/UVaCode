#include <stdio.h>


int main( void ) {
	double input[8] = {0};
	while( scanf( "%lf", &input[0] ) != -1 ) {
		int i = 0, j = 0;
		for( i = 1 ; i < 8 ; i++ )
			scanf( "%lf", &input[i] );
			
		for( i = 0 ; i < 8 ; i += 2 ) {
			for( j = i + 2 ; j < 8 ; j += 2 )
				if( input[i] == input[j] && input[i+1] == input[j+1] )
					break;

			if( j != 8 )
				break;
		}

		double x = 0, y = 0;
		int k = 0;
		for( k = 0 ; k < 8 ; k += 2 )
			if( k != i && k != j ) {
				x += input[k];
				y += input[k+1];
			}
			
		x -= input[i];
		y -= input[i+1];
		
		printf( "%.3lf %.3lf\n", x, y );
	}
	
	return 0;
}
