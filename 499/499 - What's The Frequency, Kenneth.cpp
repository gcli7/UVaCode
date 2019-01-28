#include <stdio.h>
#include <string.h>

int main( void )
{
	char input[999] = {0};
	
	while( gets( input ) ) {
		int l = strlen( input ), i, max = 0;
		char output[150] = {0};
		
		for( i = 0 ; i < l ; i++ )
			if( ( input[i] >= 'a' && input[i] <= 'z' ) ||( input[i] >= 'A' && input[i] <= 'Z' ) ) {
				output[input[i]]++;
				if( output[input[i]] > max )
					max = output[input[i]];
			}
			
		for( i = 'A' ; i <= 'Z' ; i++ )
			if( output[i] == max )
				printf("%c",i);
		for( i = 'a' ; i <= 'z' ; i++ )
			if( output[i] == max )
				printf("%c",i);
		printf(" %d\n", max);
	}
	
	return 0;	
}
