#include <stdio.h>

int main( void )
{
	long long cases = 0, now_case = 0;
	
	scanf("%lld", &cases );
	while( ++now_case <= cases ) {
		long long wall_cases = 0, now = 0, last = 0, sum_high = 0, sum_low = 0;
		
		scanf( "%lld %lld", &wall_cases, &last );
		
		while( --wall_cases ) {
			scanf( "%lld", &now );
			
			if( now > last )
				sum_high++;
			else if( now < last )
				sum_low++;
				
			last = now;
		}
		
		printf( "Case %lld: %lld %lld\n", now_case, sum_high, sum_low );
	}
	
	return 0;
}
