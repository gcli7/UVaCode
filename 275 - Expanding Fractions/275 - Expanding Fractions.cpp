#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int x = 0, y = 0;

	while(cin >> x >> y && x != 0 && y != 0) {
		map<long long int, int> base;
		string output = ".";
		int index = 0, start = 0, end = 0, counter = 0;

		base[x] = ++counter;
		while(x != 0) {
			x *= 10;
			output += (x / y) + '0';
			x %= y;
			if(base.find(x) != base.end()) {
				counter = base.find(x)->second;
				break;
			}
			base[x] = ++counter;
		}

		for(int i = 0; i < output.length(); i++) {
			if(i % 50 == 0 && i > 0)
				cout << "\n";
			cout << output[i];
		}

		if(x == 0) {
			cout << "\nThis expansion terminates.\n\n";
			continue;
		}

		for(index = 0; index < output.length(); index++) {
			for(start = index, end = output.length() - 1; start < end; start++, end--)
				if(output[start] != output[end])
					break;

			if(start < end)
				break;
		}
		cout << "\nThe last "<< output.length() - counter << " digits repeat forever.\n\n";
	}

	return 0;
}