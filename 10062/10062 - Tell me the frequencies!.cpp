#include <stdio.h>
#include <string.h>

int main( void )
{
	char input[1001] = {0};
	int flag = 0;
	
	while( gets( input ) ) {
		if( flag )
			printf("\n");
		flag = 1;
		
		int output[129] = {0}, l = strlen( input ), i = 0, large = 0, count = 0;
		
		for( i = 0 ; i < l ; i++ ) {
			output[(int)input[i]]++;
			if( output[(int)input[i]] > large )
				large = output[(int)input[i]];
		}
		
		while( ++count <= large )
			for( i = 128 ; i >= 0 ; i-- )
				if( output[i] == count )
					printf( "%d %d\n", i, output[i] );
	}
	
	return 0;
}
