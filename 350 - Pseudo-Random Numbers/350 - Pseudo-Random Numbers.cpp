#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;
	long long int z = 0, i = 0, m = 0, l = 0;

	while(cin >> z >> i >> m >> l && z != 0 && i != 0 && m != 0 && l != 0) {
		int counter = 1;
		map<int, int> base;
		map<int, int>::iterator mi;

		base[l] = counter;
		while(true) {
			counter++;
			l = (l * z + i) % m;

			if((mi = base.find(l)) != base.end()) {
				counter = counter - mi->second;
				break;
			}
			else
				base[l] = counter;
		}

		cout << "Case " << ++cases << ": " << counter << "\n";
	}

	return 0;
}