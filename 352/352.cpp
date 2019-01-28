#include <iostream>
using namespace std;

bool base[25][25];
bool input[25][25];
int len;

void check(int x, int y) {
	if(!input[x][y] || base[x][y] || x < 0 || y < 0 || x >= len || y >= len)
		return;
	
	base[x][y] = true;
	check(x - 1, y - 1);
	check(x - 1, y);
	check(x - 1, y + 1);
	check(x, y - 1);
	check(x, y + 1);
	check(x + 1, y - 1);
	check(x + 1, y);
	check(x + 1, y + 1);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	while(cin >> len) {
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++) {
				base[i][j] = false;
				input[i][j] = false;
			}

		int counter = 0;
		string temp = "";

		getline(cin, temp);
		for(int i = 0; i < len; i++) {
			getline(cin, temp);
			for(int j = 0; j < len; j++)
				if(temp[j] == '0')
					input[i][j] = false;
				else
					input[i][j] = true;
		}

		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++)
				if(input[i][j] && !base[i][j]) {
					check(i, j);
					counter++;
				}

		cout << "Image number " << ++cases << " contains " << counter << " war eagles.\n";
	}

	return 0;
}