#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int gcd(int x, int y) {
	if(y == 0)
		return x;

	gcd(y, x % y);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int l = 0;

	while(cin >> l && l) {
		int input[l];
		double counter = 0;

		for(int i = 0; i < l; i++)
			cin >> input[i];

		for(int i = 0; i < l - 1; i++)
			for(int j = i + 1; j < l; j++)
				if(gcd(input[i], input[j]) == 1)
					counter++;

		if(counter)
			cout << fixed << setprecision(6) << sqrt(((l * (l - 1)) / 2 * 6) / counter) << "\n";
		else
			cout << "No estimate for this data set.\n";
	}

	return 0;
}