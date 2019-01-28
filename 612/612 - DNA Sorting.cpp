#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct dna {
	string input;
	int inversion;
	int sequence;
}DNA;

bool cmp( DNA a, DNA b ) {
	if( a.inversion == b.inversion )
		return a.sequence < b.sequence;
		
	return a.inversion < b.inversion;
}

int main( int argc, char *argv[] ) {
	int cases = 0, flag = 0;
	
	cin >> cases;
	while( cases-- ) {
		if( flag )
			cout << endl;
		else
			flag = 1;
		
		string temp;
		int l = 0, DNACases = 0, i = 0, j = 0;
		vector<DNA> d;
		vector<DNA>::iterator itI;
		
		getline( cin, temp );
		cin >> l >> DNACases;
		getline( cin, temp );
		for( i = 0 ; i < DNACases ; i++ ) {
			getline( cin, temp );
			DNA tempDNA = { temp, 0, i };
			d.push_back( tempDNA );
		}
		
		for( itI = d.begin() ; itI != d.end() ; itI++ ) {
			temp = itI->input;
			int counter = 0, tempL = temp.length();
			
			for( i = 0 ; i < tempL ; i++ )
				for( j = i + 1 ; j < tempL ; j++ )
					if( temp[i] > temp[j] )
						counter++;
			
			itI->inversion = counter;
		}
		
		sort( d.begin(), d.end(), cmp );
		
		for( itI = d.begin() ; itI != d.end() ; itI++ )
			cout << itI->input << endl;
	}
}
