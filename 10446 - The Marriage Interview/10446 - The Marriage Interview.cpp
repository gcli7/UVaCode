#include <iostream>
#define N 61
using namespace std;

unsigned long long int output[N][N];

unsigned long long int addSum(int n, int back) {
	unsigned long long int sum = 0;
	int i = 1;

	for( ; i <= back && n - i >= 0; i++)
		sum += output[n-i][back];
	if(back - i >= 0)
		sum += back - i +1;

	return sum + 1;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < N; i++) {
		output[i][0] = 1;
		output[0][i] = 1;
		output[1][i] = 1;
		output[i][1] = i;
	}

	for(int i = 2; i < N; i++)
		for(int j = 2; j < N; j++)
			output[j][i] = addSum(j, i);

	int x = 0, y = 0, cases = 0;

	while(cin >> x >> y && x < 61 && y < 61) {
		if(x < 0)
			x = 0;
		if(y < 0)
			y = 0;

		cout << "Case " << ++cases << ": " << output[x][y] << endl;
	}

	return 0;
}