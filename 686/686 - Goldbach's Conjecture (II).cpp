#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 1 << 15;
	bool b[N+1] = {false};
	deque<int> prime;
	
	for(int i = 2; i <= N; i++)
		if(!b[i]) {
			prime.push_back(i);
			for(int j = N / i; j >= i; j--)
				if(!b[j])
					b[j*i] = true;
		}

	int input = 0;

	while(cin >> input && input) {
		int counter = 0, temp = 0;

		for(deque<int>::iterator di = prime.begin(); *di <= input / 2; di++)
			if(!b[input - *di])
				counter++;

		cout << counter << "\n";
	}

	return 0;
}