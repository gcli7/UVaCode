#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main( int argc, char *argv[] ) {
	long long int N = sqrt( 1000000000 ) + 1;
	long long int i = 0, j = 0;
	vector<int> base( N, 0 ), prime;
	vector<int>::iterator itI;
	
	for( i = 2 ; i <= N ; i++ ) {
		if( base[i] == 0 ) {
			for( j = i + i ; j <= N ; j += i )
				base[j] = 1;
		}
	}
	
	for( i = 2 ; i < base.size() ; i++ )
		if( base[i] == 0 )
			prime.push_back( i );
	
	long long int cases = 0;
	
	cin >> cases;
	while( cases-- ) {
		long long int a = 0, b = 0, maxNumber = 0, maxDivisor = 0, sumDivisor = 0, temp = 0;
		
		cin >> a >> b;
		for( i = a ; i <= b ; i++ ) {
			map<int, int> m;
			map<int, int>::iterator itJ;
			temp = i;
			for( itI = prime.begin() ; temp != 0 && temp >= *itI && itI != prime.end() ; itI++ ) {
				while( temp % ( *itI ) == 0 && temp ) {
					temp /= *itI;
					m[*itI]++;
				}
			}
			
			sumDivisor = 1;
			for( itJ = m.begin() ; itJ != m.end() ; itJ++ ) {
				sumDivisor *= ( itJ -> second ) + 1;
			}
			
			if( sumDivisor > maxDivisor ) {
				maxDivisor = sumDivisor;
				maxNumber = i;
			}
		}
		
		cout << "Between " << a << " and " << b << ", " << maxNumber << " has a maximum of " << maxDivisor << " divisors." << endl;
	}
}
