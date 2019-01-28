#include <stdio.h>
 
int isPrime( int n ) {
    int i =0, flag = 1;
    for( i = 2 ; i * i <= n ; i++ )
        if( n % i == 0 ) {
            flag = 0;
            break;
        }
    return flag;
}
 
int main(void) {
	int base[200] = {0}, i = 0, index = 0;
 
    for( i = 1 ; i < 1050 ; i++ )
        if( isPrime( i ) )
            base[index++] = i;
 
    int n = 0, c = 0;
    while( scanf( "%d %d", &n, &c ) != -1 ) {    	
        int prime[200] = {0};
        for( index = 0 ; base[index] <= n ; index++ )
            prime[index] = base[index];

		int center = 0, counter = 0;
		if( index % 2 ) 
 			counter = 2 * c - 1;
		else
			counter = 2 * c;
		
		if( counter > index )
			counter = index;
		 
 		if( index % 2 )
 			center = index / 2;
		else
			center = index / 2;
		
		i = center - ( counter / 2 );
		
		if( counter > index )
			counter = index;
		
		printf( "%d %d:", n, c );
		for( ; counter > 0 ; counter--, i++ )
			printf( " %d", prime[i] );
		printf( "\n\n" );
    }
 
	return 0;
}
