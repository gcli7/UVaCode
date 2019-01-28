#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int one[77] = {0}, two[77] = {0}, output[77] = {0};

	one[1] = 1;
	two[2] = 1;
	output[1] = 1;
	output[2] = 2;
	for(int i = 3; i < 77; i++) {
		one[i] = one[i-2] + one[i-3];
		two[i] = two[i-2] + two[i-3];
		output[i] = one[i] + one[i-1] + two[i] + two[i-1];
	}

	int input = 0;

	while(cin >> input)
		cout << output[input] << "\n";

	return 0;
}