#include <iostream>
#include <map>
using namespace std;

int counter;
map<string, int> base;

void check(string s) {
	int i = 0, j = s.length() - 1;

	for( ; i < j; i++, j--)
		if(s[i] != s[j])
			break;

	if(i >= j && base.find(s) == base.end())
		base[s] = ++counter;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(cin >> input) {
		string temp = "";
		counter = 0;
		base.clear();

		for(int i = 0; i < input.length(); i++) {
			temp = "";
			for(int j = i; j < input.length(); j++) {
				temp += input[j];
				check(temp);
			}
		}

		cout << "The string '" << input << "' contains " << counter << " palindromes.\n";
	}

	return 0;
}