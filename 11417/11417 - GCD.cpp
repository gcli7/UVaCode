#include <iostream>
using namespace std;

long long int gcd( int a, int b ) {
	if( a == 0 )
		return b;
	else if( b == 0 )
		return a;
		
	if( a > b )
		gcd( a % b, b );
	else
		gcd( a, b % a );
}

int main( int argc, char *argv[] ) {
	int input = 0;
	
	while( cin >> input && input ) {
		long long int sum = 0;
		int i = 0, j = 0;
		
		for( i = 1 ; i < input ; i++ )
			for( j = i + 1 ; j <= input ; j++ )
				sum += gcd( i, j );
				
		cout << sum << endl;
	}
}
