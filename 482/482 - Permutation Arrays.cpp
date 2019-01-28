#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	long long int cases = 0;
	bool flag = false;
	int i;
	string s;
	stringstream ss;
	vector<int> index;
	vector<string> value;

	cin >> cases;
	getline(cin, s);
	while(cases--) {
		ss.str("");
		ss.clear();
		index.clear();
		value.clear();

		if(flag)
			cout << endl;
		else
			flag = true;

		getline(cin, s);

		getline(cin, s);
		ss << s;
		while(ss >> i)
			index.push_back(i);
		ss.str("");
		ss.clear();

		getline(cin, s);
		ss << s;
		while(ss >> s)
			value.push_back(s);

		map<int, string> output;
		map<int, string>::iterator itI;
		for(i = 0; i < index.size(); i++)
				output[index[i]] = value[i];

		for(itI = output.begin(); itI != output.end(); itI++)
			cout << itI->second << endl;
	}

	return 0;
}