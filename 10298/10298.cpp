#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string input = "";

	while(cin >> input && input != ".") {
		int i = 0, j = 0;
		int l = input.length();
		string base = "";

		for(i = 1; i <= l / 2; i++) {
			if(l % i != 0)
				continue;

			base = input.substr(0, i);
			for(j = 1; j < l / i && base == input.substr(i * j, i); j++);
			if(j == l / i)
				break;
		}
		if(i > l / 2)
			cout << "1" << endl;
		else
			cout << l / i << endl;
	}

	return 0;
}