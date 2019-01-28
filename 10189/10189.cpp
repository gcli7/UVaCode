#include <stdio.h>

int main( void )
{
	int row, column, count = 0;
	
	while( scanf("%d %d", &row, &column) != EOF && row != 0 && column != 0 ) {
		if( count )
			printf("\n");
		
		char field[102][102] = {0};
		int r, c;

		for( r = 1 ; r <= row ; r++ )
				scanf("%s", &field[r][1]);

		for( r = 1 ; r <= row ; r++ )
			for( c = 1 ; c <= column ; c++ ) {
				if( field[r][c] == '.' ) {
					if( field[r-1][c-1] == '*' )
						field[r][c]++;
					if( field[r-1][c] == '*' )
						field[r][c]++;
					if( field[r-1][c+1] == '*' )
						field[r][c]++;
					if( field[r][c-1] == '*' )
						field[r][c]++;
					if( field[r][c+1] == '*' )
						field[r][c]++;
					if( field[r+1][c-1] == '*' )
						field[r][c]++;
					if( field[r+1][c] == '*' )
						field[r][c]++;
					if( field[r+1][c+1] == '*' )
						field[r][c]++;
				}
					
			}
		
		printf("Field #%d:\n", ++count);
		for( r = 1 ; r <= row ; r++ ) {
			for( c = 1 ; c <= column ; c++ ) {
				printf("%c", field[r][c] == '*' ? field[r][c] : field[r][c] - '.' + '0');
			}
			printf("\n");
		}
	}
	
	return 0;
}
