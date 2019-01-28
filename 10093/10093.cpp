#include <stdio.h>
#include <string.h>

long long f( char n ) {
	if( n <= '9' && n >= '0' )
		return ( n - '0' );
	else if( n <= 'z' && n >= 'a' )
		return ( n - 'a' + 36 );
	else
		return ( n - 'A' + 10 );
}

int main( void ) {
	char input[99999] = {0}, c = '\0';
	while( scanf( "%s", input ) != -1 ) {
		if( input[0] == '+' || input[0] == '-' )
			strcpy( input, &input[1] );
		
		long long sum = 0, l = strlen( input ), baseNumber = 0, i = 0, j = 0;
		for( i = 0 ; i < l ; i++ )
			sum += f( input[i] );
			
		c = '\0';
		for( i = 0 ; i < l ; i++ )
			if( input[i] > c )
				c = input[i];
					
		baseNumber = f( c );
		if( baseNumber < 2 )
			baseNumber = 2;
		else
			baseNumber++;	
		for( ; baseNumber < 63 ; baseNumber++ ) {
			if( sum % ( baseNumber - 1 ) == 0 )
				break;
		}
		
		if( baseNumber == 63 )
			printf( "such number is impossible!\n" );
		else
			printf( "%lld\n", baseNumber );
	}
	
	return 0;
}
