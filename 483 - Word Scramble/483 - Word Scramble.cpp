#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "", temp = "";
	stringstream ss;
	bool flag = true;

	while(getline(cin, input)) {
		ss.str("");
		ss.clear();

		ss << input;

		for(int i = 0; i < input.length(); i++)
			if(input[i] == ' ')
				cout << " ";
			else {
				ss >> temp;
				for(int j = temp.length() - 1; j >= 0; j--)
					cout << temp[j];
				i += temp.length() - 1;
			}

		cout << "\n";
	}

	return 0;
}