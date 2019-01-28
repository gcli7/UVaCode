#include <stdio.h>

long long abs( long long a , long long b)
{
	return a > b ? a - b : b - a;
}

int main( void )
{
	long long i, l, flag;
	
	while( scanf("%lld", &l) != EOF ) {
		long long input[3000] = {0};
		int control[3000] = {0};
		
		for( i = 0 ; i < l ; i++ )
			scanf("%lld", &input[i]);
		
		for( i = 1 ; i < l ; i++ )
			control[abs( input[i-1], input[i] )] = 1;
		
		flag = 1;
		for( i = 1 ; i < l ; i++ ) {
			if( control[i] == 0 ) {
				printf("Not jolly\n");
				flag = 0;
				break;
			}
		}
		if( flag )
			printf("Jolly\n");
	}
	
	return 0;
}
