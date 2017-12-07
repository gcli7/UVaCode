#include <iostream>
#include <deque>
#define N 1000001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool base[N] = {false};
	deque<int> prime;

	base[0] = true;
	base[1] = true;
	for(int i = 2; i < N; i++)
		if(!base[i]) {
			prime.push_back(i);
			for(int j = (N - 1) / i; j >= i; j--)
				if(!base[j])
					base[j*i] = true;
		}

	int input = 0;

	while(cin >> input && input != 0) {
		cout << input << " : ";

		int counter = 0;

		for(deque<int>::iterator di = prime.begin(); di != prime.end() && input > 1; di++)
			if(input % *di == 0) {
				counter++;
				while(input % *di == 0)
					input /= *di;
			}

		cout << counter << "\n";
	}

	return 0;
}