#include <iostream>
#include <vector>
using namespace std;

int main( int argc, char *argv[] ) {
	int blocks = 0;
	while( cin >> blocks ) {
		string move1, move2;
		int a = 0, b = 0, aIndex = 0, bIndex = 0, i = 0, temp = 0;
		
		vector<int> base[blocks], tempA;
		vector<int>::iterator itI;
		vector<int>::reverse_iterator itJ;
		for( i = 0 ; i < blocks ; i++ )
			base[i].push_back( i );
		
		while( 1 ) {
			cin >> move1;
			if( move1 == "quit" )
				break;
			cin >> a >> move2 >> b;
			if( a == b )
				continue;
			
			aIndex = -1;
			bIndex = -1;
			for( i = 0 ; i < blocks ; i++ )
				for( itI = base[i].begin() ; itI != base[i].end() && ( aIndex == -1 || bIndex == -1 ) ; itI++ ) {
					if( *itI == a )
						aIndex = i;
					else if( *itI == b )
						bIndex = i;
				}
			if( aIndex == bIndex )
				continue;
			
			tempA.clear();
			if( move1 == "move" ) {
				for( itJ = base[aIndex].rbegin() ; *itJ != a ; itJ++ ) {
					temp = *itJ;
					base[aIndex].pop_back();
					base[temp].push_back( temp );
				}
			}
			else {
				for( itJ = base[aIndex].rbegin() ; *itJ != a ; itJ++ ) {
					temp = *itJ;
					base[aIndex].pop_back();
					tempA.push_back( temp );
				}
			}
			temp = *itJ;
			base[aIndex].pop_back();
			tempA.push_back( temp );
			
			if( move2 == "onto" ) {
				for( itJ = base[bIndex].rbegin() ; *itJ != b ; itJ++ ) {
					temp = *itJ;
					base[bIndex].pop_back();
					base[temp].push_back( temp );
				}
			}
			
			for( itJ = tempA.rbegin() ; itJ != tempA.rend() ; itJ++ ) {
				temp = *itJ;
				tempA.pop_back();
				base[bIndex].push_back( temp );
			}
		}
		
		for( i = 0 ; i < blocks ; i++ ) {
			cout << i << ":";
			for( itI = base[i].begin() ; itI != base[i].end() ; itI++ )
				cout << " " << *itI;
			cout << endl;
		}
	}
}
