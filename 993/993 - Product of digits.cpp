#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	const int d[] = {2, 3, 5, 7};
	long long int cases = 0;
	
	cin >> cases;
	while(cases--) {
		long long int input = 0;
		int output[10] = {0};
		int i = 0, j = 0, start = 0, end = 0;
		
		cin >> input;
		if(input == 0) {
			cout << "0" << endl;
			continue;
		}
		if(input == 1) {
			cout << "1" << endl;
			continue;
		}
		
		for(i = 0; d[i]; i++)
			while(input % d[i] == 0) {
				output[d[i]]++;
				input /= d[i];
			}
			
		if(input > 1) {
			cout << "-1" << endl;
			continue;
		}

		while(output[3] >= 2) {
			output[9]++;
			output[3] -= 2;
		}
		while(output[2] >= 3) {
			output[8]++;
			output[2] -= 3;
		}
		while(output[2] >= 1 && output[3] >= 1) {
			output[6]++;
			output[2]--;
			output[3]--;
		}
		while(output[2] >= 2) {
			output[4]++;
			output[2] -= 2;
		}
		
		for(start = 1; !output[start]; start++);
		for(end = 9; !output[end]; end--);
		
		for(i = start; i <= end; i++)
			for(j = 0; j < output[i]; j++)
				cout << i;
		cout << endl;
	}
	
	return 0;
}