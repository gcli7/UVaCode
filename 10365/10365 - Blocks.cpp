#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int output[1001][3] = {0};
	int temp = 0;

	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < 3; j++)
			output[i][j] = 1000;

	for(int i = 1; i <= 1000; i++)
		for(int j = i; j <= 1000; j++)
			for(int k = j; k <= 1000; k++) {
				temp = i * j * k;

				if(temp > 1000)
					break;
				else if(i * j + j * k + i * k < output[temp][0] * output[temp][1] + output[temp][1] * output[temp][2] + output[temp][0] * output[temp][2]) {
					output[temp][0] = i;
					output[temp][1] = j;
					output[temp][2] = k;
				}
			}

	int cases = 0, input = 0;

	cin >> cases;
	while(cases--) {
		cin >> input;
		
		cout << (output[input][0] * output[input][1] + output[input][0] * output[input][2] + output[input][1] * output[input][2]) * 2 << "\n";
	}

	return 0;
}