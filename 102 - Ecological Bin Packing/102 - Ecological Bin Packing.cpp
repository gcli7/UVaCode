#include <stdio.h>

int main( void )
{
	long long input = 0;
	while( scanf( "%lld", &input ) != -1 ) {
		long long i = 0, min = 0, minIndex = -1;
		long long brown[3] = {0}, green[3] = {0}, clear[3] = {0};
		brown[0] = input;
		for( i = 0 ; i < 2 ; i++ ) {
			scanf( "%lld", &green[i] );
			scanf( "%lld", &clear[i] );
			scanf( "%lld", &brown[i+1] );
		}
		scanf( "%lld", &green[2] );
		scanf( "%lld", &clear[2] );
		
		long long output[6] = {0};
		output[0] = brown[1] + brown[2] + green[0] + green[1] + clear[0] + clear[2];
		output[1] = brown[1] + brown[2] + green[0] + green[2] + clear[0] + clear[1];
		output[2] = brown[0] + brown[2] + green[0] + green[1] + clear[1] + clear[2];
		output[3] = brown[0] + brown[1] + green[0] + green[2] + clear[1] + clear[2];
		output[4] = brown[0] + brown[2] + green[1] + green[2] + clear[0] + clear[1];
		output[5] = brown[0] + brown[1] + green[1] + green[2] + clear[0] + clear[2];
		
		min = output[0];
		minIndex = 0;
		for( i = 1 ; i < 6 ; i++ )
			if( output[i] < min ) {
				min = output[i];
				minIndex = i;
			}
			
		if( minIndex == 0 )
			printf( "BCG" );
		else if( minIndex == 1 )
			printf( "BGC" );
		else if( minIndex == 2 )
			printf( "CBG" );
		else if( minIndex == 3 )
			printf( "CGB" );
		else if( minIndex == 4 )
			printf( "GBC" );
		else
			printf( "GCB" );
			
		printf( " %lld\n", min );
	}
	
	return 0;
}
