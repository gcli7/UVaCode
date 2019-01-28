#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000000
using namespace std;

bool base[N+1];

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> prime;

	base[0] = base[1] = true;
	for(int i = 2; i <= N; i++)
		if(!base[i]) {
			for(int j = N / i; j >= i; j--)
				if(!base[j])
					base[i*j] = true;
			prime.push_back(i);
		}

	int num = 0, temp;

	while(cin >> num && num) {
		for(vector<int>::iterator vi = prime.begin(); vi != prime.end(); vi++)
			if(!base[num-*vi]) {
				cout << num << " = " << *vi << " + " << num - *vi << "\n";
				break;
			}
	}

	return 0;
}