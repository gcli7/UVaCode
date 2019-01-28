#include <iostream>
using namespace std;

int f(int n) {
	int counter = 0;
	const double r2 = (n - 0.5) * (n - 0.5);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i * i + j * j <= r2)
				counter++;

	return counter * 4;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool flag = false;
	int input = 0;
	
	while(cin >> input) {
		if(flag)
			cout << "\n";
		else
			flag = true;

		if(input == 0) {
			cout << "In the case n = 0, 0 cells contain segments of the circle.\nThere are 0 cells completely contained in the circle.\n";
			continue;
		}

		cout << "In the case n = " << input << ", " << (input - 1) * 8 + 4 << " cells contain segments of the circle.\nThere are " << f(input) << " cells completely contained in the circle.\n";
	}

	return 0;
}