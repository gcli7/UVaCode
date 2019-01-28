#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char **argv) {
	bool base[101] = {false};
	vector<int> prime;

	base[0] = true;
	base[1] = true;
	for(int i = 2; i <= 100; i++)
		if(!base[i]) {
			for(int j = 100 / i; j >= i; j--)
				if(!base[j])
					base[j*i] = true;
			
			prime.push_back(i);
		}

	int base_prime[101] = {0};
	vector<int> output[101];

	for(int i = 2; i <= 100; i++) {
		int temp = i;
		for(vector<int>::iterator vi = prime.begin(); temp > 1; vi++)
			while(temp % *vi == 0) {
				temp /= *vi;
				base_prime[*vi]++;
			}

		for(int j = 2; j <= 97; j++)
			if(base_prime[j] > 0)
				output[i].push_back(base_prime[j]);
	}

	int input = 0;

	while(cin >> input && input != 0) {
		vector<int>::iterator vi = output[input].begin();

		cout << setw(3) << input << "! =";
		for(int i = 0; vi != output[input].end() && i < 15; vi++, i++)
			cout << setw(3) << *vi;
		if(output[input].size() > 15) {
			cout << endl << "      ";
			for( ; vi != output[input].end(); vi++)
				cout << setw(3) << *vi;
		}
		cout << endl;
	}

	return 0;
}