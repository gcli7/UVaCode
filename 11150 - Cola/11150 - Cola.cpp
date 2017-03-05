#include <stdio.h>

int main( void )
{
    int n;
    
    while( scanf("%d", &n) != EOF ) {
		int sum1, sum2, sum3, temp;
		
		sum1 = temp = n;
		while( temp >= 3 ) {
			sum1 += ( temp / 3 );
			temp = ( temp / 3 ) + ( temp % 3 );
		}
		
		sum2 = n;
		temp = n + 1;
		while( temp >= 3 ) {
			sum2 += ( temp / 3 );
			temp = ( temp / 3 ) + ( temp % 3 );
		}
		
		sum3 = n;
		temp = n + 2;
		while( temp >= 3 ) {
			sum3 += ( temp / 3 );
			temp = ( temp / 3 ) + ( temp % 3 );
		}
		if( temp != 2 )
			sum3 = 0;
			
		if( sum1 < sum2 )
			sum1  = sum2;
		if( sum1 < sum3 )
			sum1 = sum3;
			
		printf("%d\n", sum1);
	}
    
    return 0;
}
