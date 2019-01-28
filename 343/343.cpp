#include <iostream>
#include <map>
using namespace std;

void fillBase(map<int, long long int> &base, string s) {
	int minBase = 0;
	int num[100] = {0};
	char c = '\0';

	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9')
			num[i] = s[i] - '0';
		else
			num[i] = s[i] - 'A' + 10;

		if(num[i] > minBase)
			minBase = num[i];
	}
	minBase++;
	if(minBase < 2)
		minBase = 2;

	for(int i = minBase; i <= 36; i++) {
		long long int sum = 0, k = 1;

		for(int j = s.length() - 1; j >= 0; j--, k *= i)
			sum += num[j] * k;

		base[i] = sum;
	}
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input = "";

	while(cin >> input) {
		map<int, long long int> f, s;
		map<int, long long int>::iterator mi, mj;

		cout << input << " ";
		fillBase(f, input);
		cin >> input;
		fillBase(s, input);

		for(mi = f.begin(); mi != f.end(); mi++) {
			for(mj = s.begin(); mj != s.end(); mj++)
				if(mi->second == mj->second)
					break;
			
			if(mj != s.end())
				break;
		}

		if(mi == f.end())
			cout << "is not equal to " << input <<" in any base 2..36\n";
		else
			cout << "(base " << mi->first << ") = " << input << " (base " << mj->first << ")\n";
	}

	return 0;
}