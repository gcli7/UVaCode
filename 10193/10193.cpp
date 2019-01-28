#include <iostream>
using namespace std;

int gcd( int a, int b ) {
	if( a == 0 )
		return b;
	else if( b == 0 )
		return a;
		
	if( a > b )
		return gcd( a % b, b );
	else
		return gcd( a, b % a );
}

int main( int argc, char *argv[] ) {
	int cases = 0, t = 0;
	
	cin >> cases;
	while( ++t <= cases ) {
		string s1, s2;
		int x = 0, y = 0, i = 0, j = 0;
		
		cin >> s1 >> s2;
		j = 1;
		for( i = s1.size() - 1 ; i >= 0 ; i-- ) {
			x += ( s1[i] - '0' ) * j;
			j *= 2;
		}
		j = 1;
		for( i = s2.size() - 1 ; i >= 0 ; i-- ) {
			y += ( s2[i] - '0' ) * j;
			j *= 2;
		}
		
		if( gcd( x, y ) == 1 )
			cout << "Pair #" << t << ": Love is not all you need!" << endl;
		else
			cout << "Pair #" << t << ": All you need is love!" << endl;
	}
}
