#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] ) {
	double a = 0, b = 0, temp = 0;
	
	while( scanf( "%lf %lf", &a, &b ) != -1 && !( a == 0 && b == 0 ) ) {
		temp = sqrt( a );
		if( temp - (int)temp == 0 )
			printf( "%d\n", (int)sqrt( b ) - (int)temp + 1 );
		else
			printf( "%d\n", (int)sqrt( b ) - (int)temp );
	}
	
	return 0;
}
