#include <stdio.h>
#include <string.h>

int main( void )
{
	int cases;
	
	while( scanf("%d", &cases) != EOF && cases != 0 ) {
		int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6, temp;
		char command[5] = {0};
		
		while( cases-- ) {
			scanf("%s", command);
			if( !strcmp( command, "north" ) ) {
				temp = top;
				top = south;
				south = bottom;
				bottom = north;
				north = temp;
			}
			else if( !strcmp( command, "east" ) ) {
				temp = top;
				top = west;
				west = bottom;
				bottom = east;
				east = temp;
			}
			else if( !strcmp( command, "south" ) ) {
				temp = top;
				top = north;
				north = bottom;
				bottom = south;
				south = temp;
			}
			else if( !strcmp( command, "west" ) ) {
				temp = top;
				top = east;
				east = bottom;
				bottom = west;
				west = temp;
			}
		}
		
		printf("%d\n", top);
	}
	
	return 0;
}
