#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int start;
	int end;
} Time;

void setFreeTime( int *time ) {
	int i = 0;
	for( ; i <= 10 ; i++ )
		time[i] = 0;
}

bool cmp( Time a, Time b ) {
	if( ( a.end - a.start ) == ( b.end - b.start ) ) {
		if( a.start == b.start )
			return a.end < b.end;
	
		return a.start < b.start;
	}
	
	return ( a.end - a.start ) < ( b.end - b.start );
}

int main( int argc, char *argv[] ) {
	int cases = 0;
	
	cin >> cases;
	while( cases-- ) {
		vector<Time> timeV;
		vector<Time>::iterator itI, itJ;
		Time time = { 0, 0 };
		int freeTime[10];
		int maxEvent = 0, counter = 0, i = 0;
		
		while( 1 ) {
			cin >> time.start >> time.end;
			if( time.start == 0 && time.end == 0 )
				break;
				
			timeV.push_back( time );
		}
		sort( timeV.begin(), timeV.end(), cmp );
		
		for( itI = timeV.begin() ; itI != timeV.end() ; itI++ ) {
			setFreeTime( freeTime );
			counter = 1;
			
			for( i = itI->start ; i < itI->end ; i++ )
				freeTime[i] = 1;
				
			for( itJ = timeV.begin() ; itJ != timeV.end() ; itJ++ ) {
				for( i = itJ->start ; i < itJ->end ; i++ )
					if( freeTime[i] )
						break;
				
				if( i == itJ->end ) {
					counter++;
					for( i = itJ->start ; i < itJ->end ; i++ )
						freeTime[i] = 1;
				}
			}
			
			if( counter > maxEvent )
				maxEvent = counter;
		}
		
		cout << maxEvent << endl;
	}
} 
