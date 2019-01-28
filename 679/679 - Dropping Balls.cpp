#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int start[22] = {0};

	start[1] = 1;
	for(int i = 2; i <= 21; i++)
		start[i] = start[i - 1] << 1;

	int cases = 0;

	cin >> cases;
	while(cases--) {
		int depth = 0, ball_th = 0, add_num = 0;

		cin >> depth >> ball_th;

		ball_th--;
		for(int i = 1; i < depth; i++) {
			add_num <<= 1;
			add_num += ball_th & 1;
			ball_th >>= 1;
		}

		cout << start[depth] + add_num << "\n";
	}

	return 0;
}