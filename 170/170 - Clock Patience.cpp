#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char **argv) {
	string input = "";

	while(cin >> input && input != "#") {
		vector<string> base[14];

		base[13].push_back(input);
		for(int i = 12; i >= 1; i--) {
			cin >> input;
			base[i].push_back(input);
		}
		for(int i = 0; i < 3; i++)
			for(int j = 13; j >= 1; j--) {
				cin >> input;
				base[j].insert(base[j].begin(), input);
			}

		bool opened[14][4] = {false};
		int suit = 0, point = 0;

		string now = base[13].back(), last = "";
		base[13].pop_back();
		switch(now[0]) {
			case 'A': point = 1;	break;
			case 'T': point = 10;	break;
			case 'J': point = 11;	break;
			case 'Q': point = 12;	break;
			case 'K': point = 13;	break;
			default: point = now[0] - '0';	break;
		}
		switch(now[1]) {
			case 'C': suit = 0;	break;
			case 'D': suit = 1;	break;
			case 'H': suit = 2;	break;
			case 'S': suit = 3;	break;
		}
		base[point].insert(base[point].begin(), now);
		while(!opened[point][suit]) {
			opened[point][suit] = true;
			last = now;
			now = base[point].back();
			base[point].pop_back();
			switch(now[0]) {
				case 'A': point = 1;	break;
				case 'T': point = 10;	break;
				case 'J': point = 11;	break;
				case 'Q': point = 12;	break;
				case 'K': point = 13;	break;
				default: point = now[0] - '0';	break;
			}
			switch(now[1]) {
				case 'C': suit = 0;	break;
				case 'D': suit = 1;	break;
				case 'H': suit = 2;	break;
				case 'S': suit = 3;	break;
			}
			base[point].insert(base[point].begin(), now);
		}

		int counter = 0;
		for(int i = 1; i <= 13; i++)
			for(int j = 0; j < 4; j++)
				if(opened[i][j])
					counter++;

		cout << setw(2) << setfill('0') << counter << "," << last << endl;
	}

	return 0;
}