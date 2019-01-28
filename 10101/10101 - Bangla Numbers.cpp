#include <stdio.h>
#include <string.h>

int main(void)
{
    long long input, cases = 1;
    int i, count;
    char icon[4][6] = { {"kuti"}, {"lakh"}, {"hajar"}, {"shata"} };
    
    while( scanf("%lld", &input) != EOF ) {
           printf("%4lld.", cases++);
           if( input < 0 ) {
               printf(" %lld\n", input);
               continue;
           }
           else if( input == 0 ) {
               printf(" %lld\n", input);
               continue;
           }
           
           int output[9]= {0};
           
           count = 0;
           while( 1 ) {
                  output[count++] = input % 100;
                  input /= 100;
                  if( input == 0 )
                      break;
                  
                  output[count++] = input % 10;
                  input /= 10;
                  if( input == 0 )
                      break;
                  
                  output[count++] = input % 100;
                  input /= 100;
                  if( input == 0 )
                      break;
                  
                  output[count++] = input % 100;
                  input /= 100;
                  if( input == 0 )
                      break;
           }

           i = -( --count % 4 ) + 4;
           if( i == 4 )
               i = 0;

           for( count ; count > 0 ; count-- ) {
                if( output[count] == 0 && i == 0 )
                    printf(" %s", icon[i++]);
                else if( output[count] == 0 )
                    i++;
                else
                    printf(" %d %s", output[count], icon[i++]);
                    
                if( i == 4 )
                    i = 0;
           }
           if( output[0] == 0 )
               printf("\n");
           else
               printf(" %d\n", output[0]);
    }

    return 0;
}
