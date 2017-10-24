#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s = "";

	while(getline(cin, s)) {
		stringstream ss(s);
		vector<long long int> c;
		long long int num = 0, sum = 0;
		bool flag = false;

		while(ss >> num)
			c.push_back(num);

		getline(cin, s);
		ss.str("");
		ss.clear();
		ss << s;

		if(c.size() == 1) {
			while(ss >> num) {
				if(flag)
					cout << " ";
				else
					flag = true;

				cout << *c.begin();
			}
			cout << "\n";

			continue;
		}

		while(ss >> num) {
			sum = *c.begin();
			for(vector<long long int>::iterator vi = c.begin() + 1; vi != c.end(); vi++)
				sum = sum * num + *vi;
			
			if(flag)
				cout << " ";
			else
				flag = true;
			cout << sum;
		}
		cout << "\n";
	}

	return 0;
}