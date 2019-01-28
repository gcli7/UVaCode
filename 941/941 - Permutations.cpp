#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

char base[20] = {0}, output[20] = {0};
bool used[20] = {0};

long long int shocked(long long int n) {
	if(n == 1 || n == 0)
		return 1;

	return n * shocked(n - 1);
}

long long int f(int now, int end) {
	map<char, int> m;

	for(int i = 0; i < end; i++)
		if(!used[i])
			m[base[i]]++;

	long long int sum = shocked(end - now - 1);
	for(map<char, int>::iterator mapI = m.begin(); mapI != m.end(); mapI++) {
		sum /= shocked(mapI->second);
	}

	return sum;
}

int main(int argc, char *argv[]) {
	long long int cases = 0;

	cin >> cases;
	while(cases--) {
		int l = 0;
		long long int counter = -1, order = 0, temp = 0;
		char last = '\0';
		for(int i = 0; i < 20; i++) {
			base[i] = '\0';
			output[i] = '\0';
			used[i] = false;
		}

		cin >> base >> order;
		l = strlen(base);
		sort(base, base + l);

		for(int i = 0; i < l; i++) {
			last = '\0';
			for(int j = 0; j < l; j++) {
				
				if(used[j] || last == base[j])
					continue;
				last = base[j];
				
				used[j] = true;
				temp = f(i, l);
				used[j] = false;
				if(counter + temp < order) {
					counter += temp;
					continue;
				}

				output[i] = base[j];
				used[j] = true;
				break;
			}
			if(strlen(output) != i + 1)
				output[i] = last;
		}

		cout << output << endl;
	}

	return 0;
}