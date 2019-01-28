#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	long long int cases = 0;
	cin >> cases;
	while( cases-- ) {
		int schedule[3700] = {0};
		int day = 0, t = 0, work = 0, i = 0;
		
		cin >> day >> t;
		while( t-- ) {
			int input = 0;
			cin >> input;
			for( i = 1 ; i * input <= day ; i++ )
				schedule[i * input] = 1;
		}
		
		for( i = 1 ; i <= day ; i++ ) {
			if( i % 7 == 6 ) {
				i++;
				continue;
			}
			if( i % 7 == 0 )
				continue;
				
			if( schedule[i] )
				work++;
		}
		
		cout << work <<endl;
	}
}
