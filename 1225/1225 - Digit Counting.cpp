#include <iostream>
#include <sstream>
using namespace std;

int main( int argc, char *argv[] ) {
	int cases = 0;
	
	cin >> cases;
	while( cases-- ) {
		long long int input = 0, i = 0;
		long long int digit[10] = {0};
		string allNumber = "";
		stringstream ss;
		
		
		cin >> input;
		for( ; input > 0 ; input-- )
			ss << input;
		allNumber = ss.str();
		i = allNumber.length();
		
		for( --i ; i >= 0 ; i-- )
			digit[allNumber[i] - '0']++;
			
		for( i = 0 ; i < 9 ; i++ )
			cout << digit[i] << " ";
		cout << digit[9] << endl;
	}
}
