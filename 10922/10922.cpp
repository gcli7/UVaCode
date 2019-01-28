#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	string input;
	
	while( getline( cin, input ) ) {
		if( input[0] == '0' )
			break;
			
		int sum = 0, i = 0;
		for( ; i < input.size() ; i++ )
			sum += input[i] - '0';
			
		if( sum % 9 )
			cout << input << " is not a multiple of 9." << endl;
		else {
			int counter = 1, temp = sum;
			while( temp != 9 ) {
				sum = 0;
				while( temp ) {
					sum += temp % 10;
					temp /= 10;
				}
				temp = sum;
				counter++;
			}
			cout << input << " is a multiple of 9 and has 9-degree " << counter << "." << endl;
		}
	}
}
