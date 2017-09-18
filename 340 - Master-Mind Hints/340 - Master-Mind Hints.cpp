#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int len = 0, cases = 0;

	while(cin >> len && len != 0) {
		cout << "Game " << ++cases << ":\n";

		int base[1005] = {0}, base_num[10] = {0};

		for(int i = 0; i < len; i++) {
			cin >> base[i];
			base_num[base[i]]++;
		}

		while(true) {
			int input[1005] = {0}, input_num[10] = {0}, d[10] = {0};
			int counter = 0;

			for(int i = 0; i < len; i++) {
				cin >> input[i];
				input_num[input[i]]++;
				if(input[i] == 0)
					counter++;
			}

			if(counter == len)
				break;

			cout << "    (";
			counter = 0;
			for(int i = 0; i < len; i++)
				if(base[i] == input[i]) {
					counter++;
					d[input[i]]++;
				}
			cout << counter << ",";
			counter = 0;
			for(int i = 1; i <= 9; i++)
				if(input_num[i] > 0 && base_num[i] > 0) {
					if(input_num[i] > base_num[i])
						counter += base_num[i] - d[i];
					else
						counter += input_num[i] - d[i];
				}
			cout << counter << ")\n";
		}
	}

	return 0;
}