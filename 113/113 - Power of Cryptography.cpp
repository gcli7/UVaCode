#include <iostream>
#include <cmath>
using namespace std;

int main( int argc, char *argv[] ) {
	double n = 0.0, p = 0.0;
	
	while( cin >> n >> p ) {
		double temp = pow( p, 1 / n );
		
		if( temp - (int)temp >= 0.5 ) 
			cout << (int)temp + 1 << endl;
		else
			cout << (int)temp << endl;
	}
}
