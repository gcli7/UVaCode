#include <iostream>
using namespace std;

bool board[8][8];
int sx, sy, ex, ey;
int min_move;

void travel(int x, int y, int counter) {
	if(board[x][y] || counter >= min_move)
		return;

	if(x == ex && y == ey) {
		if(counter < min_move)
			min_move = counter;
		return;
	}

	board[x][y] = true;

	if(x - 2 >= 0 && y + 1 < 8)
		travel(x - 2, y + 1, counter + 1);
	if(x - 2 >= 0 && y - 1 >= 0)
		travel(x - 2, y - 1, counter + 1);
	if(x - 1 >= 0 && y + 2 < 8)
		travel(x - 1, y + 2, counter + 1);
	if(x - 1 >= 0 && y - 2 >= 0)
		travel(x - 1, y - 2, counter + 1);
	if(x + 1 < 8 && y + 2 < 8)
		travel(x + 1, y + 2, counter + 1);
	if(x + 1 < 8 && y - 2 >= 0)
		travel(x + 1, y - 2, counter + 1);
	if(x + 2 < 8 && y + 1 < 8)
		travel(x + 2, y + 1, counter + 1);
	if(x + 2 < 8 && y - 1 >= 0)
		travel(x + 2, y - 1, counter + 1);

	board[x][y] = false;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string start = "", end = "";

	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			board[i][j] = false;
	while(cin >> start >> end) {
		cout << "To get from " << start << " to " << end << " takes ";

		sx = start[0] - 'a';
		sy = start[1] - '1';
		ex = end[0] - 'a';
		ey = end[1] - '1';
		
		min_move = 64;
		travel(sx, sy, 0);

		cout << min_move << " knight moves.\n";
	}

	return 0;
}