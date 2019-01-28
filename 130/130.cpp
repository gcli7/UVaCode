#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	int persons = 0, k = 0;

	while(cin >> persons >> k && persons != 0 && k != 0) {
		int base[105] = {0};
		int survivor = persons, die_index = 0, replace_index = 0, next_die_index = 0, counter = 0;

		if(persons == 1) {
			cout << "1" << endl;
			continue;
		}

		for(int i = 0; i < persons; i++)
			base[i] = i + 1;

		while(survivor > 1) {
			for(int i = 1; i < k; i++) {
				die_index = (die_index + 1) % persons;
				if(base[die_index] == -1)
					i--;
			}
			base[die_index] = -1;

			for(replace_index = (die_index + 1) % persons; base[replace_index] == -1; replace_index = (replace_index + 1) % persons);
			for(int i = 1; i < k; i++) {
				replace_index = (replace_index + 1) % persons;
				if(base[replace_index] == -1)
					i--;
			}

			base[die_index] = base[replace_index];
			base[replace_index] = -1;
			for(die_index = (die_index + 1) % persons; base[die_index] == -1; die_index = (die_index + 1) % persons);
			
			survivor--;
		}
		cout << (persons - base[die_index] + 1) % persons + 1<< endl;
	}

	return 0;
}