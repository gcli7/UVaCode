#include <stdio.h>

int main( void )
{
	int control = 0, i;
	char input[999] = {0};
	
	while( gets( input ) ) {
		for( i = 0 ; input[i] != '\0' ; i++ ) {
			if( input[i] == '"' ) {
				if( control ) {
					printf("''");
					control = 0;
				}
				else {
					printf("``");
					control = 1;
				}
			}
			else
				printf("%c", input[i]);
		}
		printf("\n");
	}
	
	return 0;
}
