#include <stdio.h>
#include <string.h>

int main( void )
{
	int row, column, r, c, board[51][51] = {0};
	char direction;
	scanf("%d %d", &row, &column);
	while( scanf("%d %d %c", &r, &c, &direction) != EOF ) {
		int i;
		char instruction[101] = {0};
		
		scanf("%s", instruction);
		for( i = 0 ; i < strlen( instruction ) ; i++ ) {
			if( instruction[i] == 'R' )
				switch( direction ) {
					case 'N': direction = 'E';	break;
					case 'E': direction = 'S';	break;
					case 'S': direction = 'W';	break;
					case 'W': direction = 'N';	break;
				}
			else if( instruction[i] == 'L' )
				switch( direction ) {
					case 'N': direction = 'W';	break;
					case 'W': direction = 'S';	break;
					case 'S': direction = 'E';	break;
					case 'E': direction = 'N';	break;
				}
			else {
				switch( direction ) {
					case 'N': c++;	break;
					case 'W': r--;	break;
					case 'S': c--;	break;
					case 'E': r++;	break;
				}

				if( r < 0 || c < 0 || r > row || c > column ) {
					switch( direction ) {
						case 'N': c--;	break;
						case 'W': r++;	break;
						case 'S': c++;	break;
						case 'E': r--;	break;
					}
					
					if( board[r][c] )
						continue;
					else {
						printf("%d %d %c LOST\n", r, c, direction);
						board[r][c] = 1;
						break;
					}
				}
			}
		}
		
		if( i == strlen( instruction ) )
			printf("%d %d %c\n", r, c, direction);
	}
	
	return 0;
}
