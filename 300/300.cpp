#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;
	const string Tbase[] = {"", "imix", "ik", "akbal", "kan", "chicchan", "cimi",
							"manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
							"ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	map<string, int> Hbase;
	Hbase["pop"] = 0;	Hbase["no"] = 1;	Hbase["zip"] = 2;
	Hbase["zotz"] = 3;	Hbase["tzec"] = 4;	Hbase["xul"] = 5;
	Hbase["yoxkin"] = 6;	Hbase["mol"] = 7;	Hbase["chen"] = 8;
	Hbase["yax"] = 9;	Hbase["zac"] = 10;	Hbase["ceh"] = 11;
	Hbase["mac"] = 12;	Hbase["kankin"] = 13;	Hbase["muan"] = 14;
	Hbase["pax"] = 15;	Hbase["koyab"] = 16;	Hbase["cumhu"] = 17;
	Hbase["uayet"] = 18;

	cin >> cases;
	cout << cases << "\n";
	while(cases--) {
		int Hyear = 0, Hday = 0, Tyear = 0, Tmonth = 0, sum = 0;
		string Hmonth = "", Tday = "";

		cin >> Hday >> Hmonth >> Hmonth >> Hyear;

		sum += Hyear * 365 + Hbase[Hmonth] * 20 + Hday;

		Tyear = sum / 260;
		sum %= 260;
		Tmonth = sum % 13 + 1;
		Tday = Tbase[sum % 20 + 1];

		cout << Tmonth << " " << Tday << " " << Tyear << "\n";
	}

	return 0;
}