#include <iostream>
using namespace std;

long long int f(long long int n) {
	while(n % 10 == 0)
		n /= 10;
	return n % 10;
}

void re(long long int a, long long int b, long long int &sum) {
	if(a == 0 && b == 0) {
		return;
	}
	if(a == 0)
		a++;

	while(a % 10 != 0 && a < b) {
		sum += a % 10;
		a++;
	}
	while(b % 10 != 0 && b > a) {
		sum += b % 10;
		b--;
	}
	sum += (b - a) / 10 * 45;

	if(a == b) {
		sum += f(a);
		return;
	}
	re(a/10, b/10, sum);
}

int main(int argc, char *argv[]) {
	long long int a = 0, b = 0;

	while(cin >> a >> b) {
		if(a < 0 && b < 0)
			break;

		long long int sum = 0;

		re(a, b, sum);

		cout << sum << endl;
	}

	return 0;
}