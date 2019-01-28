#include <iostream>
using namespace std;

string change(char c, int &n, int k) {
	switch(c) {
		case '0':	n += 0 * k;	return "0000";
		case '1':	n += 1 * k;	return "0001";
		case '2':	n += 2 * k;	return "0010";
		case '3':	n += 3 * k;	return "0011";
		case '4':	n += 4 * k;	return "0100";
		case '5':	n += 5 * k;	return "0101";
		case '6':	n += 6 * k;	return "0110";
		case '7':	n += 7 * k;	return "0111";
		case '8':	n += 8 * k;	return "1000";
		case '9':	n += 9 * k;	return "1001";
		case 'A':	n += 10 * k;	return "1010";
		case 'B':	n += 11 * k;	return "1011";
		case 'C':	n += 12 * k;	return "1100";
		case 'D':	n += 13 * k;	return "1101";
		case 'E':	n += 14 * k;	return "1110";
		case 'F':	n += 15 * k;	return "1111";
	}
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		string f_s = "", s_s = "", op = "", f_out = "", s_out = "";
		int f_v = 0, s_v = 0;

		cin >> f_s >> op >> s_s;

		for(int i = f_s.length() - 1, k = 1; i >= 0; i--, k *= 16)
			f_out = change(f_s[i], f_v, k) + f_out;
		for(int i = s_s.length() - 1, k = 1; i >= 0; i--, k *= 16)
			s_out = change(s_s[i], s_v, k) + s_out;

		while(f_out.length() < 13)
			f_out = "0" + f_out;
		while(s_out.length() < 13)
			s_out = "0" + s_out;

		cout << f_out << " " << op << " " << s_out << " = ";

		if(op == "+")
			cout << f_v + s_v << "\n";
		else
			cout << f_v - s_v << "\n";
	}

	return 0;
}