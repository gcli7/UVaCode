#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp( const void *a, const void *b ) {
	return strcmp( ( char * )a, ( char * )b );
}

int main( void ) {
	char input[75] = {0}, country[2000][75] = {0};
	int cases = 0, index = 0;
	scanf( "%d", &cases );
	while( index < cases ) {
		scanf( "%s", &country[index++][0] );
		gets( input );
	}
	
	qsort( country, index, sizeof( country[0] ), cmp );
	int i = 0, last = 0;
	char temp[75] = {0};
	
	index = 0;
	strcpy( temp, &country[0][0] );
	for( ; i < cases ; i++ ) {
		if( strcmp( temp, &country[i][0] ) != 0 ) {
			printf( "%s %d\n", temp, i - last );
			last = i;
			strcpy( temp, &country[i][0] );
		}
	}
	printf( "%s %d\n", temp, i - last );

	return 0;
}
