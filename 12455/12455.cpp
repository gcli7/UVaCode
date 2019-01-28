#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

int input[99];
int T;
int limit;
vector<int> base;
bool flag;

void f(int sum, int index) {
	if(flag || sum > limit)
		return;
	else if(sum == limit) {
		flag = true;
		return;
	}
	else
		for(int i = index + 1; i < T; i++)
			f(sum + input[i], i);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		memset(input, '\0', sizeof(input));
		flag = false;

		cin >> limit;
		cin >> T;
		for(int i = 0; i < T; i++)
			cin >> input[i];

		f(0, -1);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}