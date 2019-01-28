#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 0;

	while(cin >> n && n != 0) {
		int base[10001] = {0};

		for(int i = 0; i < n; i++)
			cin >> base[i];

		int sum = 0, max = 0;

		for(int i = 0; i < n; i++) {
			sum = 0;
			for(int j = i; j < n; j++) {
				sum += base[j];
				if(sum > max)
					max = sum;
			}
		}

		if(max == 0)
			cout << "Losing streak." << endl;
		else
			cout << "The maximum winning streak is " << max << "." << endl;
	}

	return 0;
}