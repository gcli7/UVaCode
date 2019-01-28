#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool prime(long long int n) {
	n = n * n + n + 41;
	for(long long int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;

	return true;
}

int main(int argc, char *argv[]) {
	vector<long long int> base;
	base.push_back(0);
	for(long long int i = 0, counter = 0; i <= 10000; i++) {
		if(prime(i))
			counter++;
		base.push_back(counter);
	}

	double a = 0.0, b = 0.0, temp = 0.0;
	while(cin >> a >> b) {
		if(a > b) {
			temp = a;
			a = b;
			b = temp;
		}

		temp = (base[b+1] - base[a]) * 100 / (b - a + 1);
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << temp + 0.000001 << endl;
	}

	return 0;
}