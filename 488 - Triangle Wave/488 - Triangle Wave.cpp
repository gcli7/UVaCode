#include <stdio.h>

void output( long long n )
{
	long long i = 0;
	
	for( i = 1 ; i <= n ; i++ )
		printf( "%lld", n );
	printf( "\n" );
}

int main( void )
{
	long long cases = 0, flag = 0;

	scanf("%lld", &cases);
	while( cases-- > 0 ) {
		char blank = '\0';
		long long high = 0, times = 0, i = 0;
		
		scanf("%c", &blank);
		scanf("%lld\n%lld", &high, &times);

		if( flag > 0 )
			printf( "\n" );
		flag = 1;

		while( times-- > 0 ) {
			for( i = 1 ; i < high ; i++ )
				output( i );
			for( i = high ; i > 0 ; i-- )
				output( i );
				
			if( times > 0 )
				printf( "\n" );
		}
	}
	
	return 0;
}
