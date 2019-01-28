#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct {
	string left;
	string right;
	string balance;
} Scale;

bool cmp(Scale a, Scale b) {
	if(a.balance != b.balance) {
		if(a.balance == "even")
			return false;
	}
	if(a.left.length() >= b.left.length())
		return true;
	else
		return false;

	return true;
}

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		Scale base[3];
		bool coin[12] = {false};
		int coinW[12] = {0};

		for(int i = 0; i < 3; i++)
			cin >> base[i].left >> base[i].right >> base[i].balance;

		sort(base, base + 3, cmp);

		for(int i = 0; i < 3; i++)
			if(base[i].balance == "up")
				for(int j = 0; j < base[i].left.length(); j++) {
					coinW[base[i].left[j] - 'A']++;
					coinW[base[i].right[j] - 'A']--;
				}
			else if(base[i].balance == "down")
				for(int j = 0; j < base[i].left.length(); j++) {
					coinW[base[i].left[j] - 'A']--;
					coinW[base[i].right[j] - 'A']++;
				}
			else if(base[i].balance == "even")
				for(int j = 0; j < base[i].left.length(); j++) {
					coin[base[i].left[j] - 'A'] = true;
					coin[base[i].right[j] - 'A'] = true;
				}

		int max = 0, flagW = false;
		char diff = '\0';

		for(int i = 0; i < 12; i++) {
			if(coin[i])
				coinW[i] = 0;
			
			if(abs(coinW[i]) > max) {
				max = abs(coinW[i]);
				diff = i + 'A';
				if(coinW[i] > 0)
					flagW = true;
				else
					flagW = false;
			}
		}

		cout << diff << " is the counterfeit coin and it is ";
		if(flagW)
			cout << "heavy.\n";
		else
			cout << "light.\n";
	}

	return 0;
}