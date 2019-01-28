#include <iostream>
using namespace std;

int row, column, longest;
int base[105][105];
bool used[105][105];

void travel(int x, int y, int counter) {
	if(counter > longest)
		longest = counter;

	if(used[x][y])
		return;

	used[x][y] = true;
	if(x - 1 >= 0 && base[x-1][y] < base[x][y])
		travel(x - 1, y, counter + 1);
	if(x + 1 < row && base[x+1][y] < base[x][y])
		travel(x + 1, y, counter + 1);
	if(y - 1 >= 0 && base[x][y-1] < base[x][y])
		travel(x, y - 1, counter + 1);
	if(y + 1 < column && base[x][y+1] < base[x][y])
		travel(x, y + 1, counter + 1);
	used[x][y] = false;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		string name = "";
		
		cin >> name >> row >> column;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++) {
				cin >> base[i][j];
				used[i][j] = false;
			}

		longest = 0;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
				travel(i , j, 1);

		cout << name << ": " << longest << "\n";
	}

	return 0;
}