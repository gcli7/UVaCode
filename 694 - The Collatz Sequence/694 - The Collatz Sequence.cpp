#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int value = 0, limit = 0;
	int cases = 0;

	while(cin >> value >> limit && value > 0 && limit > 0) {
		cout << "Case " << ++cases << ": A = " << value << ", limit = " << limit << ", number of terms = ";

		int counter = 1;

		while(true) {
			if(value == 1)
				break;

			if(value & 1) {
				value = value * 3 + 1;
				if(value > limit)
					break;
			}
			else
				value >>= 1;
			counter++;
		}
		cout << counter << "\n";
	}

	return 0;
}