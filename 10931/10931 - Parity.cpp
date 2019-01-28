#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	long long int input = 0;
	
	while( cin >> input && input != 0 ) {
		int binary[9999] = {0};
		int index = 0, counter = 0;
		
		while( input ) {
			binary[index] = input % 2;
			if( binary[index] )
				counter++;
			index++;
			input /= 2;
		}
		
		cout << "The parity of ";
		for( --index ; index >= 0 ; index-- )
			cout << binary[index];
		cout << " is " << counter << " (mod 2)." << endl;
	}
}
