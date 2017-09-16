#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool b[50000] = {false};
	vector<int> prime;

	b[0] = true;
	b[1] = true;
	for(int i = 2; i < 50000; i++)
		if(!b[i]) {
			for(int j = (50000 - 1) / i; j >= i; j--)
				if(!b[j])
					b[j*i] = true;
			prime.push_back(i);
		}

	long long int n = 0, k1 = 0, k2 = 0;

	while(cin >> n >> k1 && n != 0) {
		map<long long int, long long int> base, bk;
		long long int temp = 0, sum = 1;

		k2 = n - k1;
		if(k1 > k2)
			swap(k1, k2);

		for(long long int i = k2 + 1; i <= n; i++) {
			temp = i;
			for(vector<int>::iterator vi = prime.begin(); temp > 1 && vi != prime.end(); vi++)
				if(temp % *vi == 0) {
					base[*vi]++;
					temp /= *vi;
					vi--;
				}
			if(temp > 1)
				base[temp]++;
		}

		for(long long int i = k1; i > 1; i--) {
			temp = i;
			for(vector<int>::iterator vi = prime.begin(); temp > 1 && vi != prime.end(); vi++)
				if(temp % *vi == 0) {
					bk[*vi]++;
					temp /= *vi;
					vi--;
				}
			if(temp > 1)
				bk[temp]++;
		}

		for(map<long long int, long long int>::iterator mi = bk.begin(); mi != bk.end(); mi++)
			base.find(mi->first)->second -= mi->second;

		for(map<long long int, long long int>::iterator mi = base.begin(); mi != base.end(); mi++)
			for(long long int i = 0; i < mi->second; i++)
				sum *= mi->first;

		cout << sum << "\n";
	}

	return 0;
}