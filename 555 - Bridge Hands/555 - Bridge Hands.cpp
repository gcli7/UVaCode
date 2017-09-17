#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const char d[] = {'S', 'W', 'N', 'E'};
	int base[150] = {0};

	base['C'] = 0;
	base['D'] = 1;
	base['S'] = 2;
	base['H'] = 3;
	base['T'] = 10;
	base['J'] = 11;
	base['Q'] = 12;
	base['K'] = 13;
	base['A'] = 14;
	for(int i = '2'; i <= '9'; i++)
		base[i] = i - '0';

	string input = "";

	while(getline(cin, input) && input != "#") {
		int index = 0;
		vector<string> cards[4];

		switch(input[0]) {
			case 'E':	index = 0;	break;
			case 'S':	index = 1;	break;
			case 'W':	index = 2;	break;
			case 'N':	index = 3;	break;
		}

		for(int k = 0; k < 2; k++) {
			getline(cin, input);
			for(int i = 0; i < input.length(); i += 2, index++)
				cards[index%4].push_back(input.substr(i, 2));
		}

		for(int i = 0; i < 4; i++)
			for(int j = cards[i].size() - 1; j > 0; j--)
				for(int k = 0; k < j; k++) {
					int as = base[cards[i][k][0]], ar = base[cards[i][k][1]], bs = base[cards[i][k+1][0]], br = base[cards[i][k+1][1]];
					
					if((as > bs) || as == bs && ar > br) {
						input = cards[i][k];
						cards[i][k] = cards[i][k+1];
						cards[i][k+1] = input;
					}
				}

		for(int i = 0; i < 4; i++) {
			cout << d[i] << ":";
			for(vector<string>::iterator vi = cards[i].begin(); vi != cards[i].end(); vi++)
				cout << " " << *vi;
			cout << "\n";
		}
	}

	return 0;
}