#include <stdio.h>

int main( void )
{
	int start = 0, first = 0, second = 0, third = 0, sum = 0;
		
	while( 1 ) {
		scanf( "%d %d %d %d", &start, &first, &second, &third );
		if( first == 0 && second == 0 && third == 0 && start == 0 )
			break;
		sum = 360 * 3;
		
		if( start >= first )
			sum += ( start - first ) * 9;
		else
			sum += ( start + ( 40 - first ) ) * 9;
		
		if( first <= second )
			sum += ( second - first ) * 9;
		else
			sum += ( ( 40 -  first ) + second ) * 9;
		
		if( second >= third )
			sum += ( second - third ) * 9;
		else
			sum += ( second + ( 40 - third ) ) * 9;
		
		printf( "%d\n", sum );
	}
}
