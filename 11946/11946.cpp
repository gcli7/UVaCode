#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	const char base[] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};
	long long int cases = 0;
	string s = "";

	cin >> cases;
	getline(cin, s);
	while(cases--)
		while(1) {
			getline(cin, s);
			if(!s.length()) {
				if(cases)
					cout << endl;
				break;
			}

			for(int i = 0; i < s.length(); i++)
				if(s[i] >= '0' && s[i] <= '9')
					cout << base[s[i] - '0'];
				else
					cout <<s[i];
			cout << endl;
		}

	return 0;
}