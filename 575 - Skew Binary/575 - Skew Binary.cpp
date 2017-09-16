#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(cin >> input && input != "0") {
		int sum = 0, temp = 2;

		for(int i = input.length() - 1; i >= 0; i--) {
			sum += (input[i] - '0') * (temp - 1);
			temp <<= 1;
		}

		cout << sum << "\n";
	}

	return 0;
}