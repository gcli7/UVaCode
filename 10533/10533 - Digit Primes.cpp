#include <stdio.h>

#define N 1000000

long long output[N] = {0};

long long f( long long x )
{
	long long sum = 0;
	while( x > 0 ) {
		sum += x % 10;
		x /= 10;
	}
	
	return sum;
}

int main( void )
{
	long long cases, dividend, divisor, sum = 2, flag1, flag2, start, end, temp;
	output[0] = 0;	output[1] = 0;	output[2] = 1;	output[3] = 2;
	
	
	scanf("%lld", &cases);
	
	for( dividend = 4 ; dividend < N ; dividend++ ) {
		temp = f( dividend );
		if( temp == 1 )
			flag1 = 0;
		else if( temp == 2 || temp == 3 )
			flag1 = 1;
		else
			flag1 = 1;
		for( divisor = 2 ; divisor * divisor <= temp ; divisor++ ) {
			if( temp % divisor == 0 ) {
				flag1 = 0;
				break;
			}
		}
		if( !flag1 ) {
			output[dividend] = sum;
			continue;
		}
		
		flag2 = 1;
		for( divisor = 2 ; divisor * divisor <= dividend ; divisor++ ) {
			if( dividend % divisor == 0 ) {
				flag2 = 0;
				break;
			}
		}
		
		if( flag2 )
			sum++;
		output[dividend] = sum;
	}
	
	while( cases-- ) {
		scanf("%lld %lld", &start, &end);
		printf("%lld\n", output[end] - output[start-1] );
	}
	
	return 0;
}
