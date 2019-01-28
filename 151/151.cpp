#include <stdio.h>

int f( int r[], int betweenTurnOff, int allRegions )
{
	int i = 0;
	for( i = 2 ; i <= allRegions ; i++ )
				r[i] = 1;
	r[1] = 0;
				
	int hadTurnedOff = 1, temp = 1, regionIndex = 1;
	while( 1 ) {
		regionIndex++;
		if( regionIndex > allRegions )
			regionIndex = 1;
		
		if( r[regionIndex] ) {
			if( temp == betweenTurnOff ) {
				temp = 1;
				r[regionIndex] = 0;
				hadTurnedOff++;
				if( regionIndex == 13 ) {
					if( hadTurnedOff == allRegions )
						return 1;
					else
						return 0;
				}
			}
			else
				temp++;
		}
	}
}

int main( void )
{
	while( 1 ) {
		int input = 0;
		scanf( "%d", &input );
		if( input == 0 )
			break;
			
		int regions[105] = {0}, i = 0;
		for( i = 1 ; ; i++ ) {
			if( f( regions, i, input ) )
				break;
		}
		
		printf( "%d\n", i );
	}

	return 0;
} 
