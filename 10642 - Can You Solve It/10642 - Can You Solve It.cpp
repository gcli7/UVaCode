#include <iostream>
using namespace std;

long long int calculateSum( long long int X, long long int Y ) {
	long long int sum = 0;
	
	sum = ( X + Y ) * ( X + Y + 1 ) / 2;
	for( ; X >= 0 ; X-- )
		sum++;
		
	return sum;
}

int main( int argc, char *argv[] ) {
	int cases = 0, t = 0;
	
	cin >> cases;
	while( ++t <= cases ) {
		long long int sX = 0, sY = 0, eX = 0, eY = 0;
		
		cin >> sX >> sY >> eX >> eY;
		
		cout << "Case " << t << ": " << calculateSum( eX, eY ) - calculateSum( sX, sY ) << endl;
	}
}
