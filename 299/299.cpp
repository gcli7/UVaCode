#include <stdio.h>

int main( void )
{
	long long cases;
	
	scanf("%lld", &cases);
	while( cases-- ) {
		int L, i, j, train[51] = {0}, temp;
		long long count;
		
		scanf("%d", &L);
		for( i = 0 ; i < L ; i++ )
			scanf("%d", &train[i]);
			
		count = 0;
		for( i = L - 1 ; i > 0 ; i-- )
			for( j = 0 ; j < i ; j++ )
				if( train[j] > train[j+1] ) {
					temp = train[j];
					train[j] = train[j+1];
					train[j+1] = temp;
					count++;
				}
				
		printf("Optimal train swapping takes %lld swaps.\n", count);
	}
	
    return 0;
}
