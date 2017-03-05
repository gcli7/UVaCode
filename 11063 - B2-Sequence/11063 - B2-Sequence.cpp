#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
	int cases = 0, quantity = 0, i = 0, j = 0, temp = 0;
	
	while ( scanf( "%d", &quantity ) != -1 ) {
		int number[105] = {0}, base[20005] = {0}, flag = 0;
		
		scanf( "%d", &number[0] );
		if( number[0] < 1 )
				flag = 1;
		for( i = 1 ; i < quantity ; i++ ) {
			scanf( "%d", &number[i] );
			if( number[i] < 1 || number[i] < number[i-1] )
				flag = 1;
		}
		
		if( flag )
			i = -1;
		else {
			for( i = 0 ; i < quantity ; i++ ) {
				for( j = i ; j < quantity ; j++ ) {
					temp = number[i] + number[j];
					if( base[temp] )
						break;
					else
						base[temp] = 1;
				}
				if( j != quantity )
					break;
			}
		}
		
		if( i == quantity )
			printf( "Case #%d: It is a B2-Sequence.\n\n", ++cases );
		else
			printf( "Case #%d: It is not a B2-Sequence.\n\n", ++cases );
	}
	
	return 0;
}
