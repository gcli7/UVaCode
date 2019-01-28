#include <iostream>
using namespace std;

int main( int argc, char *argv[] ) {
	long long int init_height = 0, work_cats = 0;
	
	while( cin >> init_height >> work_cats ) {
		if( init_height == 0 && work_cats == 0 )
			break;
		
		long long int temp_height = 0, temp_work = 0, counter = 0, sum_no_work = 0, sum_height = 0, i = 0, j = 0;
		
		for( i = 2 ; ; i++ ) {
			temp_height = init_height;
			temp_work = work_cats;
			counter = 0;
			while( temp_height % i == 0 && temp_work % ( i - 1 ) == 0 && temp_height != 1 ) {
				temp_height /= i;
				temp_work /= ( i - 1 );
				counter++;
			}
			if( temp_work != 1 )
				continue;
			if( temp_height == 1 )
				break;
		}
		
		temp_work = 1;
		temp_height = init_height;
		for( ; counter > 0 ; counter-- ) {
			sum_no_work += temp_work;
			sum_height += temp_height * temp_work;
			temp_work *= ( i - 1 );
			temp_height /= i;
		}
		sum_height += temp_height * temp_work;
		
		cout << sum_no_work << " " << sum_height << endl;
	}
}
