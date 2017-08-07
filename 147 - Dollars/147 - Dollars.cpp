#include <iostream>
#include <iomanip>
using namespace std;
#define N 30000

int main(int argc, char *argv[]) {
	int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	long long int base[N+1] = {0};

	for(int i = 0; i <= N; i++)
		base[i] = 0;
	base[0] = 1;
	for(int i = 0; i < 11; i++)
		for(int j = coin[i]; j <= N; j++)
			base[j] += base[j-coin[i]];

	double input = 0;

	while(cin >> input && input != 0.0)
		cout << setw(6) << fixed << setprecision(2) << input << setw(17) << base[(int)(input*100 + 0.0000001)] << endl;

	return 0;
}