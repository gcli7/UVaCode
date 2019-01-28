#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int decrease(long long int n) {
	int number[11] = {0};
	int i = 0, j = 0;

	while(n > 0) {
		number[i++] = n % 10;
		n /= 10;
	}

	sort(number, number + i);
	n = 0;

	for(j = i - 1; number[j] == 0; j--);
	for( ; j >= 0; j--) {
		n *= 10;
		n += number[j];
	}

	return n;
}

long long int increase(long long int n) {
	int number[11] = {0};
	int i = 0, j = 0;

	while(n > 0) {
		number[i++] = n % 10;
		n /= 10;
	}

	sort(number, number + i);
	n = 0;

	for(j = 0; number[j] == 0; j++);
	for( ; j < i; j++) {
		n *= 10;
		n += number[j];
	}

	return n;
}

int main(int argc, char *argv[]) {
	long long int input = 0, result = 0, inOrder = 0, deOrder = 0;
	int counter = 0;
	bool flag = false;
	while(cin >> result && result != 0) {
		vector<long long int> r;

		if(flag)
			cout << endl;
		else
			flag = true;
		cout << "Original number was " << result << endl;
		
		counter = 0;
		while(true) {
			counter++;
			inOrder = increase(result);
			deOrder = decrease(result);
			result = deOrder - inOrder;
			cout << deOrder << " - " << inOrder << " = " << result << endl;
			if(find(r.begin(), r.end(),result) != r.end())
				break;
			r.push_back(result);
		}

		cout << "Chain length " << counter << endl;
	}
	cout << endl;

	return 0;
}