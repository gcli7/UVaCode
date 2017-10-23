#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<long long int> output;
	map<long long int, long long int> base;
	long long int num = 0;

	while(cin >> num) {
		base[num]++;
		if(base[num] == 1)
			output.push(num);
	}

	while(!output.empty()) {
		num = output.front();
		cout << num << " " << base[num] << "\n";
		output.pop();
	}

	return 0;
}