#include <iostream>
using namespace std;

int row, column;
bool used[105][105];

void travel(int x, int y) {
	used[x][y] = true;
	if(x - 1 >= 0 && y - 1 >= 0 && !used[x-1][y-1])
		travel(x - 1, y - 1);
	if(y - 1 >= 0 && !used[x][y-1])
		travel(x, y - 1);
	if(x + 1 < row && y - 1 >= 0 && !used[x+1][y-1])
		travel(x + 1, y - 1);
	if(x - 1 >= 0 && !used[x-1][y])
		travel(x - 1, y);
	if(x + 1 < row && !used[x+1][y])
		travel(x + 1, y);
	if(x - 1 >= 0 && y + 1 < column && !used[x-1][y+1])
		travel(x - 1, y + 1);
	if(y + 1 < column && !used[x][y+1])
		travel(x, y + 1);
	if(x + 1 < row && y + 1 < column && !used[x+1][y+1])
		travel(x + 1, y + 1);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> row >> column && row && column) {
		string s = "";
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
				used[i][j] = false;

		for(int i = 0; i < row; i++) {
			cin >> s;
			for(int j = 0; j < column; j++)
				if(s[j] == '*')
					used[i][j] = true;
		}

		int counter = 0;

		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
				if(!used[i][j]) {
					counter++;
					travel(i, j);
				}

		cout << counter << "\n";
	}

	return 0;
}