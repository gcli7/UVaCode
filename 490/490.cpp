#include <stdio.h>
#include <string.h>

int main( void )
{
    int i = 0, j, lines, str_long;
    char input[100][150] = {0};
    
    while( gets( input[i] ) )
           i++;
           
    lines = i-1;
    
    str_long = 0;
    for( i = 0 ; i <= lines ; i++ )
         if( strlen( input[i] ) > str_long )
             str_long = strlen( input[i] );
             
    for( i = 0 ; i < str_long ; i++ ) {
         for( j = lines ; j >= 0 ; j-- ) {
              if( !input[j][i] )
                  printf(" ");
              else
                  printf("%c", input[j][i]);
         }
         printf("\n");
    }

    return 0;
}
