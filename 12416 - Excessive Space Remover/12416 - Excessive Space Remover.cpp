#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(getline(cin, input)) {
		int counter = 0, max_space = 0;
		for(int i = 0; i < input.size(); i++) {
			if(input[i] == ' ') {
				counter = 0;
				do {
					counter++;
					i++;
				}
				while(i < input.size() && input[i] == ' ');
			}

			if(counter > max_space)
				max_space = counter;
		}
		
		counter = 0;
		max_space--;
		while(max_space > 0) {
			counter++;
			max_space >>= 1;
		}

		cout << counter << endl;
	}

	return 0;
}