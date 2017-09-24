#include <iostream>
#include <vector>
using namespace std;

int cases;

void printAns(vector<int> output) {
	cout << "Selection #" << ++cases << "\n";

	vector<int>::iterator vi = output.begin();
	
	cout << *vi;
	for(++vi; vi != output.end(); vi++)
		cout << " " << *vi;
	cout << "\n\n";
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num = 0, vacation = 0;
	int card[20] = {0};

	cases = 0;
	while(cin >> num >> vacation) {
		for(int i = 0; i < 20; i++)
			cin >> card[i];
		
		vector<int> person;
		vector<int>::iterator vi;

		for(int i = 1; i <= num; i++)
			person.push_back(i);

		if(num <= vacation) {
			printAns(person);
			continue;
		}

		for(int i = 0; i < 20; i++) {
			int counter = 0;

			for(int j = card[i] - 1; j < person.size(); j += card[i]) {
				person[j] = 0;
				counter++;
				if(person.size() - counter <= vacation)
					break;
			}

			for(vi = person.begin(); vi != person.end(); vi++)
				if(*vi == 0) {
					person.erase(vi);
					vi--;
				}

			if(person.size() <= vacation)
				break;
		}

		printAns(person);
	}

	return 0;
}