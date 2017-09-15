#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const string base = "aeiouAEIOU";
	string input = "", temp = "";
	bool flag = true;

	while(getline(cin, input)) {
		for(int i = 0; i < input.length(); i++) {
			if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
				temp += input[i];
				if(i != input.length() - 1)
					continue;
			}
			else if(temp == "") {
				cout << input[i];
				continue;
			}
			
			flag = false;
			for(int j = 0; j < base.length(); j++)
				if(temp[0] == base[j]) {
					flag = true;
					break;
				}

			if(flag)
				cout << temp << "ay";
			else
				cout << temp.substr(1, temp.length() - 1) << temp[0] << "ay";

			if(!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')))
				cout << input[i];

			temp = "";
		}
		cout << "\n";
	}

	return 0;
}