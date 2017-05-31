#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	unsigned long long int input = 0, start = 0, end = 0;

	while(cin >> input && input != 0) {
		start = input * 10 / 9;
		end = start;

		while(start - start / 10 == input)
			start--;

		while(end - end / 10 == input)
			end++;

		cout << ++start;
		end--;
		while(++start <= end)
			cout << " " << start;
		cout << endl;
	}

	return 0;
}