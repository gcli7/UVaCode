#include <iostream>
#include <map>
#include <iomanip>
#define N 60000
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	map<int, string> base;

	base[1] = "DEFICIENT";
	for(int i = 2; i <= N; i++) {
		int sum = 1;
		for(int j = 2; j * j <= i; j++)
			if(i % j == 0) {
				if(j == i / j)
					sum += j;
				else
					sum += j + (i / j);
			}

		if(sum > i)
			base[i] = "ABUNDANT";
		else if(sum == i)
			base[i] = "PERFECT";
		else
			base[i] = "DEFICIENT";
	}

	int input = 0;

	cout << "PERFECTION OUTPUT\n";
	while(cin >> input && input != 0)
		cout << setw(5) << input << "  " << base[input] << "\n";
	cout << "END OF OUTPUT\n";

	return 0;
}