#include <stdio.h>
#include <string.h>

int emirp( long n ) {
        int i = 2;
		long flag = n;

        for( ; i * i <= n ; i++ )
                if( n % i == 0 )
                        break;

        if( i * i <= n )
                return 0;

        long re[15] = {0};
        i = 0;
        while( n > 0 ) {
                re[i++] = n % 10;
                n /= 10;
        }

        int j = 0, k = 0;
        for( i-- ; i >= 0 ; j++, i--  ) {
                for( k = i ; k > 0 ; k-- )
                        re[j] *= 10;
                n += re[j];
		}
		
		if( flag == n )
			return 1;

        for( i = 2 ; i * i <= n ; i++ )
                if( n % i == 0 )
                        break;

        if( i * i <= n )
                return 1;

        return 2;
}

int main( void ) {
	long n = 0;
	while( scanf( "%ld", &n ) != -1 ) {
		if( emirp( n ) == 0 )
			printf( "%ld is not prime.\n", n );
		else if( emirp( n ) ==  1 )
			printf( "%ld is prime.\n", n );
		else
			printf( "%ld is emirp.\n", n );
	}
	
	return 0;
}
