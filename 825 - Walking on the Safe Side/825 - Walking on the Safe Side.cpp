#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	int cases = 0;
	string s = "";
	stringstream ss;
	bool blank = false;

	cin >> cases;
	getline(cin, s);
	while(cases--) {
		if(blank)
			cout << endl;
		else
			blank = true;

		getline(cin, s);
		int x = 0, y = 0, temp = 0;
		int base[99][99] = {0};

		cin >> x >> y;
		getline(cin, s);

		for(int i = 1; i <= x; i++) {
			getline(cin, s);
			ss << s;
			ss >> temp;
			while(ss >> temp)
				base[i][temp] = -1;
			ss.str("");
			ss.clear();
		}

		int start_index = 1;
		for( ; start_index <= x && start_index <= y && base[start_index][1] == -1 && base[1][start_index] == - 1; start_index++) {
			base[start_index][1] = 0;
			base[1][start_index] = 0;
		}

		for(temp = start_index; temp <= x && base[temp][1] != -1; temp++)
			base[temp][1] = 1;
		base[temp][1] = 0;
		for(temp = start_index; temp <= y && base[1][temp] != -1; temp++)
			base[1][temp] = 1;
		base[1][temp] = 0;

		for(int i = 2; i <= x; i++)
			for(int j = 2; j <= y; j++) {
				if(base[i][j] == -1)
					base[i][j] = 0;
				else
					base[i][j] += base[i-1][j] + base[i][j-1];
			}

		cout << base[x][y] << endl;
	}

	return 0;
}