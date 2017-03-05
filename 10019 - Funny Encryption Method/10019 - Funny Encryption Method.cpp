#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	int cases = 0;
	cin >> cases;
	while( cases-- ) {
		int input = 0, b1 = 0, b2 = 0, temp = 0;
		
		cin >> input;

		temp = input;
		while( temp ) {
			if( temp % 2 )
				b1++;
			temp /= 2;
		}

		while( input ) {
			switch( input % 10 ) {
				case 1:	b2++;	break;
				case 2:	b2++;	break;
				case 3:	b2 += 2;	break;
				case 4:	b2++;	break;
				case 5:	b2 += 2;	break;
				case 6:	b2 += 2;	break;
				case 7:	b2 += 3;	break;
				case 8:	b2++;	break;
				case 9:	b2 += 2;	break;
				default:	break;
			}
			input /= 10;
		}
		
		cout << b1 << " " << b2 << endl;
	}
}
