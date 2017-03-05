#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main( int argc, char *argv[] ) {
	int flag = 0;
	long long int cases = 0;
	string input;
	
	cin >> cases;
	getline( cin, input );
	getline( cin, input );
		
	while( cases-- ) {
		if( flag )
			cout << endl;
		else
			flag = 1;      
		
		map< string, int > tree;
		map< string, int >::iterator it;
		double sum = 0;
		
		while( getline( cin, input ) && !input.empty() ) {
			it = tree.find( input );
			if( it == tree.end() )
				tree[input] = 1;
			else
				tree[input]++;
			sum++;
		}
		
		for( it = tree.begin() ; it != tree.end() ; it++ )
			cout << it->first << " " << fixed << setprecision( 4 ) << (double)it->second / sum * 100 << endl;
	}
}
