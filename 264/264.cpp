#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	map<int, long long int> base;
	map<int, long long int>::iterator mapI;
	int i = 0;
	long long int temp = 0;

	base[1] = 1;
	for(i = 2; temp <= 10000000; i++) {
		temp = ((1 + i) * i) / 2;
		base[i] = temp;
	}

	long long int input = 0;
	while(cin >> input) {
		int number1 = 0, number2 = 1;

		for(mapI = base.begin(); mapI->second < input; mapI++);
		number1 = mapI->first - 1;
		temp = ((1 + number1) * number1) / 2 + 1;
		number1++;
		while(temp < input) {
			number1--;
			number2++;
			temp++;
		}

		cout << "TERM " << input <<" IS ";
		if(mapI->first % 2)
			cout << number1 << "/" << number2 << endl;
		else
			cout << number2 << "/" << number1 << endl;
	}

	return 0;
}