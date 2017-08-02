#include <iostream>
#include <algorithm>
using namespace std;
#define N 30001

int main(int argc, char *argvp[]) {
	int coin[] = {1, 5, 10, 25, 50};
	long long int base[N] = {0};

	base[0] = 1;
	for(int i = 0; i < 5; i++)
		for(int j = coin[i]; j < N; j++)
			base[j] += base[j - coin[i]];

	int input = 0;

	while(cin >> input) {
		if(base[input] == 1)
			cout << "There is only 1 way to produce " << input <<" cents change." << endl;
		else
			cout << "There are " << base[input] << " ways to produce " << input << " cents change." << endl;
	}

	return 0;
}