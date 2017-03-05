#include <stdio.h>
#include <string.h>


int main( void ) {
	long long cases = 0, flag = 0;
	scanf( "%lld", &cases );
	getchar();
	getchar();
	while( cases-- ) {
		if( flag )
			printf( "\n" );
  		else
			flag = 1;
		
		char p[70] = {0}, c[70] = {0}, s[500] = {0};
		gets( p );
		gets( c );
  		printf( "%s\n%s\n", c, p );
  		
  		int i = 0, l = strlen( p );
  		for( ; i < l ; i++ )
			s[(int)p[i]+150] = c[i];
			
  		while( gets( p ) ) {
  			if( p[0] == '\0' )
				break;
			
			l = strlen( p );
			for( i = 0 ; i < l ; i++ )
				if( s[(int)p[i]+150] != '\0' )
					printf( "%c", s[(int)p[i]+150] );
				else
					printf( "%c", p[i] );
			printf( "\n" );
		}
	}
	
	return 0;
}
