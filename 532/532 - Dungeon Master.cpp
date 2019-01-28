#include <iostream>
#include <queue>
#define N 35
using namespace std;

typedef struct qaz {
	int x, y, z, step;
} Node;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int level = 0, row = 0, column = 0;

	while(cin >> level >> row >> column && level != 0 && row != 0 && column != 0) {
		int sx = 0, sy = 0, sz = 0, ex = 0, ey = 0, ez = 0;
		bool used[N][N][N] = {false};
		string s = "";

		for(int i = 1; i <= level; i++) {
			getline(cin, s);
			for(int j = 1; j <= row; j++) {
				getline(cin, s);
				for(int k = 0; k < s.length(); k++)
					if(s[k] == '#')
						used[i][j][k+1] = true;
					else if(s[k] == 'S') {
						sx = i;
						sy = j;
						sz = k + 1;
					}
					else if(s[k] == 'E') {
						ex = i;
						ey = j;
						ez = k + 1;
					}
			}
		}

		queue<Node> q;
		Node node = {sx, sy, sz, 0};
		bool flag = true;

		q.push(node);
		used[1][1][1] = true;

		while(!q.empty()) {
			node = q.front();
			q.pop();

			if(node.x == ex && node.y == ey && node.z == ez) {
				cout << "Escaped in " << node.step << " minute(s).\n";
				flag = false;
				break;
			}

			if(node.x - 1 > 0 && !used[node.x-1][node.y][node.z]) {
				Node n = {node.x - 1, node.y, node.z, node.step + 1};
				q.push(n);
				used[node.x-1][node.y][node.z] = true;
			}
			if(node.x + 1 <= level && !used[node.x+1][node.y][node.z]) {
				Node n = {node.x + 1, node.y, node.z, node.step + 1};
				q.push(n);
				used[node.x+1][node.y][node.z] = true;
			}
			if(node.y - 1 > 0 && !used[node.x][node.y-1][node.z]) {
				Node n = {node.x, node.y - 1, node.z, node.step + 1};
				q.push(n);
				used[node.x][node.y-1][node.z] = true;
			}
			if(node.y + 1 <= row && !used[node.x][node.y+1][node.z]) {
				Node n = {node.x, node.y + 1, node.z, node.step + 1};
				q.push(n);
				used[node.x][node.y+1][node.z] = true;
			}
			if(node.z - 1 > 0 && !used[node.x][node.y][node.z-1]) {
				Node n = {node.x, node.y, node.z - 1, node.step + 1};
				q.push(n);
				used[node.x][node.y][node.z-1] = true;
			}
			if(node.z + 1 <= column && !used[node.x][node.y][node.z+1]) {
				Node n = {node.x, node.y, node.z + 1, node.step + 1};
				q.push(n);
				used[node.x][node.y][node.z+1] = true;
			}
		}

		if(flag)
			cout << "Trapped!\n";
	}

	return 0;
}