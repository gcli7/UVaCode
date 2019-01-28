#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;
	string s = "";

	cin >> cases;
	getline(cin, s);
	while(cases--) {
		getline(cin, s);
		for(int i = 0; i < s.length(); i++)
			if(s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') {
				s = s.substr(0, i) + s.substr(i + 1);
				i--;
			}

		deque<char> base;
		int i = 0;

		for( ; i < s.length(); i++) {
			if(s[i] == '(' || s[i] == '[')
				base.push_back(s[i]);
			else if(!base.empty() && ((s[i] == ')' && base.back() == '(') || (s[i] == ']' && base.back() == '[')))
				base.pop_back();
			else
				break;
		}

		if(i == s.length() && base.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}