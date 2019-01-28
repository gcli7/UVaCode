#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = 0;

int cmp( const void *a, const void *b )
{
	return *(char *)a - *(char *)b;
}

void permutation( char b[], char temp[], char out[], int used[], char in[],int index, int size )
{
	if( index == size ) {
		strcpy( out, temp );
		if( flag == 0 )
			flag = 1;
		else
			flag = 0;
		return;
	}
	
	int i = 0;
	char last = '\0';
	for( i = 0 ; i < size ; i++ ) {
		if( used[i] == 0 && last != b[i] && ( b[i] == in[index] || flag == 1 ) ) {
			last = b[i];
			used[i] = 1;
			temp[index] = b[i];
			permutation( b, temp, out, used, in, index + 1, size );
			used[i] = 0;
		}
	}
}

int main(void)
{	
	char id[99] = {0};
	scanf( "%s", id );
	while( strcmp( id, "#" ) != 0 ) {
		int l = strlen( id ), used[99] = {0}, same = 0;
		char base[99] = {0}, output[99] = {0}, temp[99] = {0};
		strcpy( base, id );
		qsort( base, l, sizeof( char ), cmp );
		
		flag = 0;
		permutation( base, temp, output, used, id, 0, l );
		
		if( strlen( output ) == 0 || flag == 1 )
			printf( "No Successor\n" );
		else
			printf( "%s\n", output );
		
		scanf( "%s", id );
	}
	
	return 0;
}
