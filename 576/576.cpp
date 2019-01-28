#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(getline(cin, input) && input != "e/o/i") {
		int index = 0, counter = 0;
		int s[3] = {0};

		if(input[0] == 'a' || input[0] == 'e' || input[0] == 'i' || input[0] == 'o' || input[0] == 'u' || input[0] == 'y')
			counter++;
		for(int i = 1, j = 0; i < input.length(); i++) {
			if(input[i] == '/') {
				s[j++] = counter;
				counter = 0;
			}
			else if((input[i-1] != 'a' && input[i-1] != 'e' && input[i-1] != 'i' && input[i-1] != 'o' && input[i-1] != 'u' && input[i-1] != 'y') &&
					(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'y'))
				counter++;
		}
		s[2] = counter;

		if(s[0] != 5)
			cout << "1\n";
		else if(s[1] != 7)
			cout << "2\n";
		else if(s[2] != 5)
			cout << "3\n";
		else
			cout << "Y\n";
	}

	return 0;
}