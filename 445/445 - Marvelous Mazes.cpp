#include <iostream>
using namespace std;

void display(char output, int times) {
	if(output == 'b')
		output = ' ';

	while(times--)
		cout << output;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(getline(cin, input)) {
		if(input == "") {
			cout << "\n";
			continue;
		}

		int counter = 0;

		for(int i =0; i < input.length(); i++)
			if(input[i] >= '0' && input[i] <= '9')
				counter += input[i] - '0';
			else if(input[i] == '!')
				cout << "\n";
			else {
				display(input[i], counter);
				counter = 0;
			}

		cout << "\n";
	}

	return 0;
}