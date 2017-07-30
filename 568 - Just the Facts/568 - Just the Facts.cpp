#include <iostream>
#include <iomanip>
#define N 10000
using namespace std;

int main(int argc, char *argv[]) {
	long long base[10005] = {0};
	base[0] = 1;

	for(int i = 1; i <= N; i++) {
		base[i] = base[i-1] * i;
		while(base[i] % 10 == 0)
			base[i] /= 10;
		if(base[i] > 1000000)
			base[i] %= 1000000;
	}

	int input = 0;

	while(cin >> input)
		cout  << setw(5) << input << " -> " << base[input] % 10 << endl;

	return 0;
}