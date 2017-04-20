#include <iostream>
#include <map>
#include <limits>
using namespace std;

int main(int argc, char *argv[]) {
	map<int, long long int> base;
	map<int, long long int>::iterator mapI;
	long long int temp = 0;

	base[0] = 0;
	for(long long int i = 1; temp <= numeric_limits<int>::max(); i++) {
		temp += i;
		base[i] = temp * 2;
	}

	long long int cases = 0;

	cin >> cases;
	while(cases--) {
		int start = 0, end = 0, max = 0;

		cin >> start >> end;
		if(start > end) {
			temp = start;
			start = end;
			end = temp;
		}

		if(start == end) {
			cout << "0" << endl;
			continue;
		}
		else if(end - start == 1) {
			cout << "1" << endl;
			continue;
		}

		temp = end - start;
		for(mapI = base.begin(); mapI->second < temp; mapI++);

		if(temp == mapI->second)
			cout << mapI->first * 2 << endl;
		else {
			mapI--;
			if(temp - mapI->second <= mapI->first + 1)
				cout << mapI->first * 2 + 1 << endl;
			else
				cout << mapI->first * 2 + 2 << endl;
		}
	}

	return 0;
}