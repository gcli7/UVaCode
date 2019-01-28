#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0, temp = 0, num = 0;
	string s = "";

	while(cin >> temp >> num && temp != 0 && num != 0) {
		if(cases)
			cout << "\n";

		string company = "";
		double money = (int)0x7fffffff, m = 0.0;
		int match_num = 0;

		for(int i = 0; i <= temp; i++)
			getline(cin, s);

		while(num--) {
			getline(cin, s);
			cin >> m >> temp;

			if(temp > match_num || (temp == match_num && m < money)) {
				company = s;
				money = m;
				match_num = temp;
			}

			for(int i = 0; i <= temp; i++)
				getline(cin, s);
		}

		cout << "RFP #" << ++cases << "\n" << company << "\n";
	}

	return 0;
}