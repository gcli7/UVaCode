#include <stdio.h>
#include <string.h>

int main(void)
{
    int cases, i, l, letter[26] = {0}, bigest = 0;
    
    scanf("%d\n", &cases);
    while( cases-- ) {
           char input[99] = {0};
           gets(input);
           l = strlen( input );
           
           for( i = 0 ; i < l ; i++ ) {
                if( input[i] >= 'a' && input[i] <= 'z' )
                    letter[input[i]-'a']++;
                else if( input[i] >= 'A' && input[i] <= 'Z' )
                    letter[input[i]-'A']++;
           }
    }
    
    for( i = 0 ; i < 26 ; i++ )
         if( letter[i] > bigest )
             bigest = letter[i];
             
    for( ; bigest > 0 ; bigest-- )
         for( i = 0 ; i < 26 ; i++ ) {
              if( letter[i] == bigest )
                  printf("%c %d\n", i+'A', letter[i]);
         }
    
    return 0;
}
