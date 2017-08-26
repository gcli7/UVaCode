#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);

	string input = "";

	while(cin >> input) {
		string first = input.substr(0, 6), second = input.substr(6, 6);
		vector<string> dice, possible;
		vector<string>::iterator vi;

		dice.push_back(first);
		dice.push_back(first.substr(1, 1) + first.substr(5, 1) + first.substr(2, 1) + first.substr(3, 1) + first.substr(0, 1) + first.substr(4, 1));
		dice.push_back(first.substr(2, 1) + first.substr(1, 1) + first.substr(5, 1) + first.substr(0, 1) + first.substr(4, 1) + first.substr(3, 1));
		dice.push_back(first.substr(3, 1) + first.substr(1, 1) + first.substr(0, 1) + first.substr(5, 1) + first.substr(4, 1) + first.substr(2, 1));
		dice.push_back(first.substr(4, 1) + first.substr(0, 1) + first.substr(2, 1) + first.substr(3, 1) + first.substr(5, 1) + first.substr(1, 1));
		dice.push_back(first.substr(5, 1) + first.substr(1, 1) + first.substr(3, 1) + first.substr(2, 1) + first.substr(4, 1) + first.substr(0, 1));

		for(vi = dice.begin(); vi != dice.end(); vi++)
			if(second[0] == (*vi)[0]) {
				first = *vi;
				possible.push_back(first);
				possible.push_back(first.substr(0, 1) + first.substr(3, 1) + first.substr(1, 1) + first.substr(4, 1) + first.substr(2, 1) + first.substr(5, 1));
				possible.push_back(first.substr(0, 1) + first.substr(4, 1) + first.substr(3, 1) + first.substr(2, 1) + first.substr(1, 1) + first.substr(5, 1));
				possible.push_back(first.substr(0, 1) + first.substr(2, 1) + first.substr(4, 1) + first.substr(1, 1) + first.substr(3, 1) + first.substr(5, 1));
			}

		for(vi = possible.begin(); vi != possible.end(); vi++)
			if(*vi == second)
				break;
		if(vi == possible.end())
			cout << "FALSE" << endl;
		else
			cout << "TRUE" << endl;
	}

	return 0;
}