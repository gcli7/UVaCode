#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int f(int n) {
	return n * n;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int limit[] = {99, 9999, 999999, 99999999};
	const int x[] = {10, 100, 1000, 10000};
	vector<int> base[4];

	for(int i = 0; i < 4; i++)
		for(int j = 0; j <= limit[i]; j++)
			if(f((j%x[i]) + (j/x[i])) == j)
				base[i].push_back(j);

	int input = 0, w = 0;

	while(cin >> input) {
		w = input;
		input = input / 2 - 1;
		for(vector<int>::iterator vi = base[input].begin(); vi != base[input].end(); vi++)
			cout << setw(w) << setfill('0') << *vi << endl;
	}

	return 0;
}