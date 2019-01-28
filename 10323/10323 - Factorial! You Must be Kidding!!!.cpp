#include <iostream>
#include <map>
using namespace std;
#define UL 6227020800
#define LL 10000

int main(int argc, char *argv[]) {
	int i = 1;
	long long temp = 1;
	map<int, long long> base;
	map<int, long long>::iterator mi;

	while(temp <= LL) {
		temp *= i;
		i++;
	}

	do {
		base[i-1] = temp;
		temp *= i;
		i++;
	} while(temp <= UL);


	int input = 0;

	while(cin >> input) {
		if((mi = base.find(input)) != base.end()) {
			cout << mi->second << endl;
			continue;
		}

		if(input < 0) {
			if(input % 2)
				cout << "Overflow!" << endl;
			else
				cout << "Underflow!" << endl;
		}
		else if(input < 8)
			cout << "Underflow!" << endl;
		else
			cout << "Overflow!" << endl;
	}

	return 0;
}