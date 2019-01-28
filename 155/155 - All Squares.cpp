#include <iostream>
#include <iomanip>
using namespace std;

int x, y, counter;

void check(int k, int kx, int ky) {
	int x_right = kx + k, x_left = kx - k, y_top = ky + k, y_bottom = ky - k;

	if(x_right == x_left)
		return;

	if(x <= x_right && x >= x_left && y <= y_top && y >= y_bottom)
		counter++;

	if(k < 1)
		return;

	check(k / 2, x_left, y_top);
	check(k / 2, x_left, y_bottom);
	check(k / 2, x_right, y_bottom);
	check(k / 2, x_right, y_top);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k = 0;

	while(cin >> k >> x >> y && k !=0 && x != 0 && y != 0) {
		counter = 0;

		check(k, 1024, 1024);

		cout << setw(3) << counter << "\n";
	}

	return 0;
}