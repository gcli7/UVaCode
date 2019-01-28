#include <iostream>
#include <vector>
using namespace std;

typedef struct m {
	string name;
	int t;
} Med;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		int type = 0, stop = 0, counter = 0;
		Med temp;
		vector<Med> base;

		cin >> type >> stop;
		for(int i = 0; i < type; i++) {
			cin >> temp.name >> temp.t;
			base.push_back(temp);
		}

		for(int times = 1; counter < stop; times++)
			for(vector<Med>::iterator vi = base.begin(); vi != base.end(); vi++)
				if(times % vi->t == 0) {
					counter++;
					cout << times << " " << vi->name << "\n";
					if(counter >= stop)
						break;
				}
	}

	return 0;
}