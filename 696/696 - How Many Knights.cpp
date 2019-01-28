#include <iostream>
using namespace std;

int knights(int x, int y) {
	if(x > y) {
		int temp = y;
		y = x;
		x = temp;
	}

	if(x == 1)
		return y;
	if(x == 2 && y % 4 == 0)
		return y;
	if(x == 2 && y & 1)
		return y + 1;
	if(x == 2)
		return y + 2;
	if(x * y & 1)
		return (x * y) / 2 + 1;
	return (x * y) / 2;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x = 0, y = 0;

	while(cin >> x >> y && (x != 0 || y != 0)) {
		cout << knights(x, y) << " knights may be placed on a " << x << " row " << y << " column board.\n";
	}

	return 0;
}