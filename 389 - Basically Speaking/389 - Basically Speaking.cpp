#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";
	int fb = 0, sb = 0;

	while(cin >> input >> fb >> sb) {
		int f = 1, num = 0;
		vector<int> output;
		string s = "";

		for(int i = input.length() - 1; i >= 0 ; i--, f *= fb)
			switch(input[i]) {
				case '0'...'9':	num += (input[i] - '0') * f;	break;
				case 'A'...'F':	num += (input[i] - 'A' + 10) *f;	break;
			}

		do {
			output.push_back(num % sb);
			num /= sb;
		}
		while(num > 0);

		for(vector<int>::reverse_iterator vi = output.rbegin(); vi != output.rend(); vi++)
			if(*vi >= 0 && *vi <= 9)
				s += *vi + '0';
			else
				s += *vi + 'A' - 10;

		if(s.length() <= 7)
			cout << setw(7) << s << "\n";
		else
			cout << "  ERROR\n";
	}

	return 0;
}