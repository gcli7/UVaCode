#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

typedef struct node {
	int value;
	string level;
} Node;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(cin >> input) {
		Node base[260];
		map<string, bool> canUse;
		int num = 0, temp = 0;

		while(input != "()") {
			for(temp = 0; input[temp] != ','; temp++);
				base[num].value = atoi(input.substr(1, temp - 1).c_str());

			if(input[temp+1] == ')')
				base[num].level = "";
			else
				base[num].level = input.substr(temp + 1, input.length() - temp - 2);

			num++;
			cin >> input;
		}

		for(int i = num - 1; i > 0; i--)
			for(int j = 0; j < i; j++) {
				bool flag = false;

				if(base[j].level.length() > base[j+1].level.length())
					flag = true;
				else if(base[j].level.length() == base[j+1].level.length()) {
					for(int k = 0; k < base[j].level.length(); k++)
						if(base[j].level[k] == 'L' && base[j+1].level[k] == 'R')
							break;
						else if(base[j].level[k] == 'R' && base[j+1].level[k] == 'L') {
							flag = true;
							break;
						}
				}


				if(flag) {
					temp = base[j].value;
					input = base[j].level;
					base[j].value = base[j+1].value;
					base[j].level = base[j+1].level;
					base[j+1].value = temp;
					base[j+1].level = input;
				}
			}

		if(base[0].level.length() != 0) {
			cout << "not complete\n";
			continue;
		}

		canUse["R"] = true;
		canUse["L"] = true;
		canUse[""] = false;
		for(temp = 1; temp < num; temp++)
			if(canUse.find(base[temp].level) == canUse.end() || !canUse.find(base[temp].level)->second)
				break;
			else {
				canUse[base[temp].level + "R"] = true;
				canUse[base[temp].level + "L"] = true;
				canUse[base[temp].level] = false;
			}
		
		if(temp < num) {
			cout << "not complete\n";
			continue;
		}

		cout << base[0].value;
		for(int i = 1; i < num; i++)
			cout << " " << base[i].value;
		cout << "\n";
	}

	return 0;
}