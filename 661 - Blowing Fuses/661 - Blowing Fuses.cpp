#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int device_num = 0, times = 0, fuse = 0, cases = 0;

	while(cin >> device_num >> times >> fuse && !(device_num == 0 && times == 0 && fuse == 0) ) {
		cout << "Sequence " << ++cases << "\n";

		int temp = 0, sum = 0, max = 0;
		int device[21] = {0};
		bool turn[21] = {false};
		bool flag = true;

		for(int i = 1; i <= device_num; i++)
			cin >> device[i];

		for(int i = 0; i < times; i++) {
			cin >> temp;

			if(turn[temp]) {
				turn[temp] = false;
				sum -= device[temp];
			}
			else {
				turn[temp] = true;
				sum += device[temp];
				if(sum > fuse) {
					cout << "Fuse was blown.\n\n";

					flag = false;
					for(int j = i + 1; j < times; j++)
						cin >> temp;

					break;
				}
			}

			if(sum > max)
				max = sum;
		}

		if(flag) {
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << max << " amperes.\n\n";
		}
	}

	return 0;
}