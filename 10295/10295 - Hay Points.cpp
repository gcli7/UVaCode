#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	map<string, long long int> base;
	map<string, long long int>::iterator mapI;
	long long int counter = 0, employee = 0, temp = 0, sum = 0;
	string s = "";

	cin >> counter >> employee;
	while(counter--) {
		cin >> s >> temp;
		base[s] = temp;
	}

	while(employee--) {
		sum = 0;
		while(cin >> s && s != ".") {
			mapI = base.find(s);
			if(mapI != base.end())
				sum += mapI->second;
		}
		cout << sum << endl;
	}

	return 0;
}