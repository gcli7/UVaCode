#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0, len1 = 0, len2 = 0;

	while(cin >> len1 >> len2 && len1 != 0 && len2 != 0) {
		cout << "Twin Towers #" << ++cases << "\nNumber of Tiles : ";

		int ft[105] = {0}, st[105] = {0}, base[105][105] = {0};

		for(int i = 1; i <= len1; i++)
			cin >> ft[i];
		for(int i = 1; i <= len2; i++)
			cin >> st[i];

		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
				if(ft[i] == st[j])
					base[i][j] = base[i-1][j-1] + 1;
				else
					base[i][j] = max(base[i-1][j], base[i][j-1]);

		cout << base[len1][len2] << "\n\n";
	}

	return 0;
}