#include <iostream>
using namespace std;
#define N 7489

int main(int argc, char *argv[]) {
	int coin[] = {5, 10, 25, 50};
	int base[N+1] = {0};

	for(int i = 0; i <= N; i++)
		base[i] = 1;
	for(int i = 0; i < 4; i++)
		for(int j = coin[i]; j <= N; j++)
			base[j] += base[j-coin[i]];

	int input = 0;

	while(cin >> input)
		cout << base[input] << endl;

	return 0;
}