#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		string first = "", second = "";
		vector<string> base, possible;
		vector<string>::iterator vi;

		cin >> first >> second;

		base.push_back(first);
		base.push_back(first.substr(1, 1) + first.substr(0, 1) + first.substr(2, 1) + first.substr(5, 1) + first.substr(4, 1) + first.substr(3, 1));
		base.push_back(first.substr(3, 1) + first.substr(5, 1) + first.substr(2, 1) + first.substr(1, 1) + first.substr(4, 1) + first.substr(0, 1));
		base.push_back(first.substr(5, 1) + first.substr(3, 1) + first.substr(2, 1) + first.substr(0, 1) + first.substr(4, 1) + first.substr(1, 1));
		base.push_back(first.substr(2, 1) + first.substr(4, 1) + first.substr(1, 1) + first.substr(3, 1) + first.substr(0, 1) + first.substr(5, 1));
		base.push_back(first.substr(4, 1) + first.substr(2, 1) + first.substr(1, 1) + first.substr(5, 1) + first.substr(0, 1) + first.substr(3, 1));

		for(vi = base.begin(); vi != base.end(); vi++)
			if(second[0] == (*vi)[0] && second[1] == (*vi)[1])
				possible.push_back(*vi);

		for(vi = possible.begin(); vi != possible.end(); vi++) {
			if(second.substr(2, 4) == (*vi).substr(2, 4) || second.substr(2, 4) == (*vi).substr(3, 3) + (*vi).substr(2, 1) || second.substr(2, 4) == (*vi).substr(4, 2) + (*vi).substr(2, 2) || second.substr(2, 4) == (*vi).substr(5, 1) + (*vi).substr(2, 3))
				break;
		}	
		
		if(vi != possible.end())
			cout << "Equal" << endl;
		else
			cout << "Not Equal" << endl;
	}

	return 0;
}