#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int size = 0;

	while(cin >> size && size > 0) {
		int base[size][size] = {0};
		int sum = 0, oddRow = 0, oddColumn = 0, oddRowCounter = 0, oddColumnCounter = 0;

		for(int i = 0; i < size; i++) {
			sum = 0;
			for(int j = 0; j < size; j++) {
				cin >> base[i][j];
				sum += base[i][j];
			}
			if(sum % 2) {
				oddRowCounter++;
				oddRow = i;
			}
		}

		for(int i = 0; i < size; i++) {
			sum = 0;
			for(int j = 0; j < size; j++)
				sum += base[j][i];
			if(sum % 2) {
				oddColumnCounter++;
				oddColumn = i;
			}
		}

		if(oddRowCounter == 0 && oddColumnCounter == 0)
			cout << "OK" << endl;
		else if(oddRowCounter == 1 && oddColumnCounter == 1)
			cout << "Change bit (" << oddRow + 1 << "," << oddColumn + 1 << ")" << endl;
		else
			cout << "Corrupt" << endl;
	}

	return 0;
}