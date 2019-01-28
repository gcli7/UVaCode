#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dictionary[105][150] = {0};
	int dic_num = 0;
	vector<string> base;
	string input = "";

	while(cin >> input && input != "XXXXXX") {
		base.push_back(input);
		for(int i = 0; i < input.length(); i++)
			dictionary[dic_num][input[i]]++;
		dic_num++;
	}

	while(cin >> input && input != "XXXXXX") {
		int b[150] = {0};
		vector<string> output;

		for(int i = 0; i < input.length(); i++)
			b[input[i]]++;

		for(int i = 0; i < dic_num; i++) {
			int j = 'a';
			for( ; j <= 'z'; j++)
				if(b[j] != dictionary[i][j])
					break;
			if(j > 'z')
				output.push_back(base[i]);
		}

		if(output.empty())
			cout << "NOT A VALID WORD\n";
		else {
			sort(output.begin(), output.end());
			for(vector<string>::iterator vi = output.begin(); vi != output.end(); vi++)
				cout << *vi << "\n";
		}
		cout << "******\n";
	}

	return 0;
}