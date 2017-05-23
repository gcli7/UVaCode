#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 250
using namespace std;

void f(int &x, int &y) {
	char number[N] = {0};
	char c = '\0';
	int i = 0, temp = 0;
	bool xFlag = false, flag = true;

	while(scanf("%c", &c) != -1) {
		if(c == '+' || c == '-' || c == '=' || c == '\n'){
			if(xFlag && flag) {
				if(number[0] == '-')
					temp = -1;
				else
					temp = 1;
			}
			else
				temp = atoi(number);

			if(xFlag)
				x += temp;
			else
				y += temp;

			number[0] = c;
			for(i = 1; number[i]; i++)
				number[i] = '\0';

			if(c == '=' || c == '\n')
				break;

			i = 1;
			xFlag = false;
			flag = true;
		}
		else if(c == 'x')
			xFlag = true;
		else {
			number[i++] = c;
			flag = false;
		}
	}
}

int main(int argc, char *argv[]) {
	int cases = 0;

	cin >> cases;
	getchar();
	while(cases--) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

		f(x1, y1);
		f(x2, y2);

		x1 -= x2;
		y2 -= y1;

		if(x1 == 0 && y2 == 0)
			cout << "IDENTITY" << endl;
		else if(x1 == 0 && y2 != 0)
			cout << "IMPOSSIBLE" << endl;
		else {
			double ans = (double)y2 / x1;

			if(ans - (int)ans == 0)
				cout << (int)ans << endl;
			else {
				if(ans > 0)
					cout << (int)ans << endl;
				else
					cout << (int)ans - 1 << endl;
			}
		}
	}

	return 0;
}