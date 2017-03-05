#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	int cases = 0;
	
	cin >> cases;
	while( cases-- ) {
		int m = 0, n = 0, nodes = 0, i = 0, j = 0;
		char base[105][105] = {0};
		
		cin >> m >> n >> nodes;
		cout << m << " " << n << " " << nodes << endl;
		
		for( i = 0 ; i < m ; i++ )
			for( j = 0 ; j < n ; j++ )
				cin >> base[i][j];

		while( nodes-- ) {
			int x = 0, y = 0, counter = 1, flag = 0;
			char center = '\0';
			
			cin >> x >> y;
			center = base[x][y];
			
			for( i = 1 ; ; i++ ) {
				if( x - i >= 0 && x + i < m && y - i >= 0 && y + i < n ) {
					for( j = x - i ; j <= x + i ; j++ )
						if( base[j][y-i] != center || base[j][y+i] != center ) {
							flag = 1;
							break;
						}
						
					for( j = y - i ; j <= y + i ; j++ )
						if( base[x-i][j] != center || base[x+i][j] != center ) {
							flag = 1;
							break;
						}
				}
				else
					flag = 1;
					
				if( flag )
					break;
				else
					counter += 2;
			}
			
			cout << counter << endl;
		}
	}
}
