#include <cstdio>
using namespace std;

int r, c, now, next;
char base[2][105][105];

void fight(int i, int j, char self, char enemy) {
	if((i - 1 >= 0 && base[now][i-1][j] == enemy) ||
	   (j - 1 >= 0 && base[now][i][j-1] == enemy) ||
	   (i + 1 < r && base[now][i+1][j] == enemy) ||
	   (j + 1 < c && base[now][i][j+1] == enemy))
		base[next][i][j] = enemy;
	else
		base[next][i][j] = self;
}

int main(int argc, char **argv) {
	int cases = 0;

	scanf("%d", &cases);
	while(cases--) {
		int d = 0;
		r = 0;
		c = 0;
		now = 0;
		next = 1;

		scanf("%d %d %d", &r, &c, &d);
		for(int i = 0; i < r; i++) {
			scanf("%c", &base[0][i][0]);
			for(int j = 0; j < c; j++)
				scanf("%c", &base[0][i][j]);
		}

		while(d--) {
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					switch(base[now][i][j]) {
						case 'R':	fight(i, j, 'R', 'P');	break;
						case 'P':	fight(i, j, 'P', 'S');	break;
						case 'S':	fight(i, j, 'S', 'R');	break;
						default:	break;
					}

			now = (now + 1) & 1;
			next = (next + 1) & 1;
		}

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++)
				printf("%c", base[now][i][j]);
			printf("\n");
		}

		if(cases)
			printf("\n");
	}

	return 0;
}