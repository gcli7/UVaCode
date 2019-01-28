#include <iostream>
#include <map>
#define N 100000000
using namespace std;

int main(int argc, char *argv[]) {
	long long int base[20000] = {0};
	long long int sum = 0;
	for(long long int i = 0; sum <= N; i++) {
		sum += i;
		base[i] = sum;
	}

	long long int input = 0;

	while(cin >> input && input != 0) {
		long long int output1 = 0, output2 = 0;

		while(base[output2++] <= input);
		output2 -= 2;

		input -= base[output2];
		output2++;

		if(input == 0)
			output1 = output2;
		else
			output1 = output2 - input;

		cout << output1 << " " << output2 << endl;
	}

	return 0;
}