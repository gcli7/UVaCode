#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	double high = 0, up = 0, down = 0, tired = 0;

	while(cin >> high >> up >> down >> tired && high != 0) {
		int day = 1;
		double now = 0;

		tired = (tired / 100) * up;
		while(true) {
			now += up;
			if(now > high)
				break;
			now -= down;
			if(now < 0)
				break;
			up -= tired;
			if(up < 0)
				up = 0;
			day++;
		}

		if(now >= high)
			cout << "success on day " << day << "\n";
		else
			cout << "failure on day " << day << "\n";
	}

	return 0;
}