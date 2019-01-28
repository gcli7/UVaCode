#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		long long int base[35][35] = {0};
		bool disconnect[35][35][2] = {false};
		int len = 0, sx = 0, sy = 0, ex = 0, ey = 0, num = 0;

		cin >> len >> sx >> sy >> ex >> ey >> num;
		while(num--) {
			int x = 0, y = 0;
			char d = '\0';

			cin >> x >> y >> d;
			if(d == 'W')
				disconnect[x][y][0] = true;
			else if(d == 'S')
				disconnect[x][y][1] = true;
			else if(d == 'E')
				disconnect[x+1][y][0] = true;
			else
				disconnect[x][y+1][1] = true;
		}

		base[sx][sy] = 1;
		for(int i = sx; i <= ex; i++)
			for(int j = sy; j <= ey; j++) {
				if(!disconnect[i][j][0])
					base[i][j] += base[i-1][j];
				if(!disconnect[i][j][1])
					base[i][j] += base[i][j-1];
			}
		
		cout << base[ex][ey] << "\n";
	}

	return 0;
}