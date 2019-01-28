#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	long long int number = 0, d = 0;
	
	while( cin >> number >> d ) {
		if( d <= 1 || number <= 1 ) {
			cout << "Boring!" << endl;
			continue;
		}
		
		int sequence[99] = {0};
		int index = 0, temp = number;
		
		while( temp > 1 ) {
			if( temp % d )
				break;
				
			temp /= d;
			sequence[index++] = temp;
		}
		
		if( temp != 1 )
			cout << "Boring!" << endl;
		else {
			int i = 0;
			
			cout << number;
			for( ; i < index ; i++ )
				cout << " " << sequence[i];
			cout << endl;
		}
	}
}
