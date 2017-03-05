#include <stdio.h>

int main(void)
{
    long int v, t;
    
    while( scanf("%ld%ld", &v, &t) != EOF )
           printf("%ld\n", 2 * v * t);
    
    return 0;
}
