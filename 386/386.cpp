#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int base = 0, sum = 0;

	for(long long int i = 2; i <= 200; i++)
		for(long long int j = 2; j <= 200; j++)
			for(long long int k = j; k <= 200; k++)
				for(long long int l = k; l <= 200; l++) {
					base = i * i * i;
					sum = j * j * j + k * k * k + l * l * l;

					if(base == sum)
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
					else if(base < sum)
						break;
				}

	return 0;
}