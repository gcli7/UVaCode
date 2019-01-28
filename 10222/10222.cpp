#include <stdio.h>
#include <string.h>

void f( char ch )
{
     switch( ch ) {
             case 'e': printf("q"); break;
             case 'd': printf("a"); break;
             case 'c': printf("z"); break;
             case 'r': printf("w"); break;
             case 'f': printf("s"); break;
             case 'v': printf("x"); break;
             case 't': printf("e"); break;
             case 'g': printf("d"); break;
             case 'b': printf("c"); break;
             case 'y': printf("r"); break;
             case 'h': printf("f"); break;
             case 'n': printf("v"); break;
             case 'u': printf("t"); break;
             case 'j': printf("g"); break;
             case 'm': printf("b"); break;
             case 'i': printf("y"); break;
             case 'k': printf("h"); break;
             case ',': printf("n"); break;
             case 'o': printf("u"); break;
             case 'l': printf("j"); break;
             case '.': printf("m"); break;
             case 'p': printf("i"); break;
             case ';': printf("k"); break;
             case '[': printf("o"); break;
             case '\'': printf("l"); break;
             case ']': printf("p"); break;
             case 'E': printf("q"); break;
             case 'D': printf("a"); break;
             case 'C': printf("z"); break;
             case 'R': printf("w"); break;
             case 'F': printf("s"); break;
             case 'V': printf("x"); break;
             case 'T': printf("e"); break;
             case 'G': printf("d"); break;
             case 'B': printf("c"); break;
             case 'Y': printf("r"); break;
             case 'H': printf("f"); break;
             case 'N': printf("v"); break;
             case 'U': printf("t"); break;
             case 'J': printf("g"); break;
             case 'M': printf("b"); break;
             case 'I': printf("y"); break;
             case 'K': printf("h"); break;
             case 'O': printf("u"); break;
             case 'L': printf("j"); break;
             case 'P': printf("i"); break;
             default: printf("%c", ch); break;
     }
}

int main(void)
{
    int i;
    char input[99] = {0};
    
    gets( input );
    for( i = 0 ; i < strlen( input ) ; i++ )
         f( input[i] );
    printf("\n");

    return 0;
}
