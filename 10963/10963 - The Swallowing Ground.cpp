#include<stdio.h>

int main()
{
	int blank = 0;
	long long cases = 0;
	scanf( "%lld", &cases );
	while( cases-- ) {
		if( blank )
			printf( "\n" );
		else
			blank = 1;
		
		int lines = 0, flag = 1;
		scanf( "%d", &lines );
		
		int a = 0, b = 0, temp = 0;
		scanf( "%d %d", &a, &b );
		temp = a - b;
		while( --lines ) {
			scanf( "%d %d", &a, &b );
			if( a - b != temp && a - b != 0 - temp )
				flag = 0;
		}
		
		if( flag )
			printf( "yes\n" );
		else
			printf( "no\n" );
	}
	
	return 0;
}
