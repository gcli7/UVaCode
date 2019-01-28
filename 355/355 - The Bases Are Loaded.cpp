#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int fBase = 0, sBase = 0;
	string s = "";

	while(cin >> sBase >> fBase >> s) {
		int sNum[15] = {0};
		long long int sSum = 0, temp = 0;
		string output = "";

		for(int i = 0; i < s.length(); i++) {
			if(s[i] >= '0' && s[i] <= '9')
				sNum[i] = s[i] - '0';
			else
				sNum[i] = s[i] - 'A' + 10;

			if(sNum[i] > temp)
				temp = sNum[i];
		}
		if(sBase < ++temp) {
			cout << s << " is an illegal base " << sBase << " number\n";
			continue;
		}

		temp = 1;
		for(int i = s.length() - 1; i >= 0; i--, temp *= sBase)
			sSum += sNum[i] * temp;

		while(sSum) {
			temp = sSum % fBase;
			if(temp <= 9)
				output = (char)(temp + '0') + output;
			else
				output = (char)(temp + 'A' - 10) + output;
			sSum /= fBase;
		}

		if(output == "")
			cout << s << " base " << sBase << " = 0 base " << fBase << "\n";
		else
			cout << s << " base " << sBase << " = " << output << " base " << fBase << "\n";
	}

	return 0;
}