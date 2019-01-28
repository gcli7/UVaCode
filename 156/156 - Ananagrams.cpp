#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct in {
	char origin[40];
	char afterSort[40];
	int flag;
};

typedef struct in In;

int cmpSort(const void *a, const void *b)
{
	return strcmp( ( (In *)a )->afterSort, ( (In *)b )->afterSort );
}

int cmpOrigin(const void *a, const void *b)
{
	return strcmp( ( (In *)a )->origin, ( (In *)b )->origin );
}

int cmpChar(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int main( void )
{
	char input[40] = {0};
	In base[1005] = {0};
	int index = 0, i = 0, l = 0;
	
	while( scanf( "%s", input ) && input[0] != '#' ) {
		strcpy( base[index].origin, input );
		l = strlen( input );
		for( i = 0 ; i < l ; i++ )
			if( input[i] >= 'A' && input[i] <= 'Z' )
				input[i] = input[i] - 'A' + 'a';
		
		qsort( input, l, sizeof( char ), cmpChar );
		strcpy( base[index++].afterSort, input );
	}
	
	qsort( base, index, sizeof( base[0] ), cmpSort );
	
	for( i = 0 ; i < index - 1 ; i++ ) {
		if( strcmp( base[i].afterSort, base[i+1].afterSort ) == 0 ) {
			base[i].flag = 1;
			base[i+1].flag = 1;
			for( l = i + 2 ; strcmp( base[i].afterSort, base[l].afterSort ) == 0 && l < index - 1 ; l++ )
				base[l].flag = 1;
			i = l - 1;
		}
	}
	
	qsort( base, index, sizeof( base[0] ), cmpOrigin );
	
	for( i = 0 ; i < index ; i++ )
		if( base[i].flag == 0 )
			printf( "%s\n", base[i].origin );
			
	return 0;
}
