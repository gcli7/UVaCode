#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int base[9] = {0};

	while(cin >> base[8]) {
		for(int i = 7; i >= 0; i--)
			cin >> base[i];

		string output = "";
		stringstream ss;

		for(int index = 8; index > 1; index--) {
			if(base[index] == 0)
				continue;

			if(base[index] > 0)
				ss << " + ";
			else {
				ss << " - ";
				base[index] = 0 - base[index];
			}

			if(base[index] != 1)
				ss << base[index];
			
			ss << "x^" << index;
		}

		if(base[1] != 0) {
			if(base[1] > 0)
				ss << " + ";
			else {
				ss << " - ";
				base[1] = 0 - base[1];
			}

			if(base[1] != 1)
				ss << base[1];
			
			ss << "x";
		}

		if(base[0] != 0) {
			if(base[0] > 0)
				ss << " + ";
			else {
				ss << " - ";
				base[0] = 0 - base[0];
			}

			ss << base[0];
		}

		getline(ss, output);

		if(output == "")
			cout << "0\n";
		else if(output[1] == '+')
			cout << output.substr(3, output.length() - 3) << "\n";
		else
			cout << "-" << output.substr(3, output.length() - 3) << "\n";
	}

	return 0;
}