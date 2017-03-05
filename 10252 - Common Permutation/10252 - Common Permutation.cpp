#include <stdio.h>
#include <string.h>

void count_letter( char word[], int l, int let[] )
{
	int i;
	
	for( i = 0 ; i < l ; i++ )
		let[word[i]-'a']++;
}

int main( void )
{
	char a[1001] = {0}, b[1001] = {0};
	while( gets( a ) ) {
		gets( b );
		
		int letter_a[26] = {0}, letter_b[26] = {0}, i, j;
		
		count_letter( a, strlen( a ), letter_a );
		count_letter( b, strlen( b ), letter_b );
			
		for( i = 0 ; i < 26 ; i++ )
			if( letter_a[i] > letter_b[i] )
				letter_a[i] = letter_b[i];
				
		for( i = 0 ; i < 26 ; i++ ) {
			for( j = 0 ; j < letter_a[i] ; j++ )
				printf("%c", 'a'+i);
		}
		
		printf("\n");
	}
	
	return 0;
}
