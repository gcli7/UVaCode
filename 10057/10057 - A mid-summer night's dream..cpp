#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main( int argc, char *argv[] ) {
	long long int index = 0;
	
	while( cin >> index ) {
		vector< int > queue;
		vector< int >::iterator itI;
		long long int i = 0, midIndex = 0, counter = 1;
		int temp = 0, midNumber = 0;
		
		for( i = 0 ; i < index ; i++ ) {
			cin >> temp;
			queue.push_back( temp );
		}
		sort( queue.begin(), queue.end() );
		
		if( index % 2 )
			midIndex = index / 2;
		else
			midIndex = ( index / 2 ) - 1;
		midNumber = queue.at( midIndex );
		
		for( i = midIndex - 1 ; i >= 0 && queue.at( i ) == midNumber ; i--, counter++ );
		for( i = midIndex + 1 ; i < index && queue.at( i ) == midNumber ; i++, counter++ );
		
		if( index % 2 )
			cout << midNumber << " " << counter << " 1" << endl;
		else {
			if( midNumber != queue.at( midIndex + 1 ) ) {
				midNumber = queue.at( midIndex + 1 );
				for( i = midIndex + 1 ; i < index && queue.at( i ) == midNumber ; i++, counter++ );
			}
			
			cout << queue.at( midIndex ) << " " << counter << " " << midNumber - queue.at( midIndex ) + 1 << endl;
		}
	}
}
