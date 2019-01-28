#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#define N 32767
using namespace std;

int pow(int x, int y) {
	int sum = 1;

	for(int i = 0; i < y; i++)
		sum *= x;

	return sum;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool base[N+1] = {false};
	vector<int> prime;

	base[0] = base[1] = true;
	for(int i = 2; i <= N; i++)
		if(!base[i]) {
			for(int j = N / i; j >= i; j--)
				if(!base[j])
					base[i*j] = true;
			prime.push_back(i);
		}

	string s = "";

	while(getline(cin, s) && s != "0") {
		stringstream ss(s);
		int num = 1, x = 0, y = 0;

		while(ss >> x) {
			ss >> y;
			num *= pow(x, y);
		}
		num--;

		map<int, int> output;

		vector<int>::iterator vi = prime.begin();
		while(num > 1) {
			if(num % *vi == 0) {
				output[*vi]++;
				num /= *vi;
			}
			else
				vi++;
		}

		map<int, int>::reverse_iterator mi = output.rbegin();
		cout << mi->first << " " << mi->second;
		for(mi++; mi != output.rend(); mi++)
			cout << " " << mi->first << " " << mi->second;
		cout << "\n";
	}

	return 0;
}