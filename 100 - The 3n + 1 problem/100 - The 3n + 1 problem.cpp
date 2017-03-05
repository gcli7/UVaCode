#include <stdio.h>

int main( void )
{
	long long start = 0, end = 0, count = 0, temp = 0, temp_count = 0, i = 0;
	
	while( scanf( "%lld %lld", &start, &end ) !=EOF ) {
		count = 1;
		
		printf("%lld %lld ", start, end );
		
		if( start > end ) {
			temp = start;
			start = end;
			end = temp;
		}
		
		for( i = start ; i <= end ; i++ ) {
			temp_count = 1;
			temp = i;
			
			while( temp != 1 ) {
				if( temp % 2 )
					temp = temp * 3 + 1;
				else 
					temp = temp / 2;
					
				temp_count++;
			}
			
			if( temp_count > count )
				count = temp_count;
		}
		
		printf("%lld\n", count);
	}
	
	return 0;
}
