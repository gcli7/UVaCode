#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int output[51] = {0};

	output[0] = 1;
	output[1] = 1;
	for(int i = 2; i < 51; i++)
		output[i] = output[i-1] + output[i-2];

	int input = 0;

	while(cin >> input && input != 0)
		cout << output[input] << "\n";

	return 0;
}