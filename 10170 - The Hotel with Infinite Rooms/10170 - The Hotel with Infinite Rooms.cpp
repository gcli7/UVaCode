#include <stdio.h>

int main( int argc, char *argv[] ) {
	long long int members = 0, day = 0;
	while( scanf( "%lld %lld", &members, &day ) != -1 ) {
		long long sum = members;
		while( sum < day )
			sum += ++members;
			
		printf( "%lld\n", members );
	}
	
	return 0;
}
