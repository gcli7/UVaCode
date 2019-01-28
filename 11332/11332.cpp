#include <stdio.h>

int main( void )
{
    int temp, i;
    long long input;
    
    while( scanf("%lld", &input) != EOF && input != 0 ) {
           while( input >= 10 ) {
                  temp = 0;
                  while( input > 0 ) {
                         temp += input % 10;
                         input /= 10;
                  }
                  input = temp;
           }
           printf("%lld\n", input);
    }
    
    return 0;
}
