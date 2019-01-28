#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	int cases = 0;
	
	cin >> cases;
	while( cases-- ) {
		long long int input = 0, reserve = 0, counter = 0, temp = 0;
		
		cin >> input;
		while( 1 ) {
			reserve = 0;
			temp = input;
			
			while( temp ) {
				reserve *= 10;
				reserve += temp % 10;
				temp /= 10;
			}
			if( input == reserve && counter )
				break;
			else
				input += reserve;
				
			counter++;
		}
		
		cout << counter << " " << input << endl;
	}
}
