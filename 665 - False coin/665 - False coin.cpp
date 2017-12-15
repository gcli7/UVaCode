#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;
	bool flag = false;

	cin >> cases;

	while(cases--) {
		if(flag)
			cout << "\n";
		else
			flag = true;

		int coin_num = 0, estimate = 0;
		int coin_value[105] ={0};
		bool coin_true[105] = {false};

		cin >> coin_num >> estimate;

		while(estimate--) {
			char op = '\0';
			string s = "";

			getline(cin, s);
			getline(cin, s);
			cin >> op;

			if(op == '=') {
				stringstream ss(s);
				int temp = 0;

				ss >> temp;
				while(ss >> temp)
					coin_true[temp] = true;
			}
			else if(op == '<') {
				stringstream ss(s);
				int temp = 0, l = 0;

				ss >> l;
				for(int i = 0; i < l; i++) {
					ss >> temp;
					coin_value[temp]--;
				}
				for(int i = 0; i < l; i++) {
					ss >> temp;
					coin_value[temp]++;
				}
			}
			else {
				stringstream ss(s);
				int temp = 0, l = 0;

				ss >> l;
				for(int i = 0; i < l; i++) {
					ss >> temp;
					coin_value[temp]++;
				}
				for(int i = 0; i < l; i++) {
					ss >> temp;
					coin_value[temp]--;
				}
			}
		}

		int max = 0, index = 0, counter = 1, false_conuter = 0, false_index = 0;

		for(int i = 1; i <= coin_num; i++)
			if(!coin_true[i]) {
				if(abs(coin_value[i]) > max) {
					max = abs(coin_value[i]);
					index = i;
					counter = 1;
				}
				else if(abs(coin_value[i]) == max)
					counter++;

				false_conuter++;
				false_index = i;
			}
		
		if(counter == 1)
			cout << index << "\n";
		else if(false_conuter == 1)
			cout << false_index << "\n";
		else
			cout << "0\n";
	}

	return 0;
}