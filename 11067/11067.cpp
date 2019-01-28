#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int basex = 0, basey = 0;
	
	while(cin >> basex >> basey && (basex != 0 || basey != 0)) {
		int base[105][105] = {0};
		int wolf = 0, x = 0, y = 0;
		
		cin >> wolf;
		while(wolf--) {
			cin >> x >> y;
			base[x][y] = -1;
		}
		
		base[0][0] = 1;
		for(x = 0; x <= basex; x++)
			for(y = 0; y <= basey; y++) {
				if(base[x][y] == -1)
					continue;
				if(x - 1 >= 0 && base[x-1][y] != -1)
					base[x][y] += base[x-1][y];
				if(y - 1 >= 0 && base[x][y-1] != -1)
					base[x][y] += base[x][y-1];
			}
			
		if(base[basex][basey] == 0)
			cout << "There is no path." << endl;
		else if(base[basex][basey] == 1)
			cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
		else
			cout << "There are " << base[basex][basey] << " paths from Little Red Riding Hood's house to her grandmother's house." << endl;
	}
	
	return 0;
}
