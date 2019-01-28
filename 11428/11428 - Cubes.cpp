#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	map<int, int> storage;
	int max = 0;
	
	storage[1] = 1;
	for(max = 2; max * max * max - storage[max-1] <= 10000; max++)
		storage[max] = max * max * max;
	
	
	map<int, pair<int, int> > base;
	map<int, pair<int, int> >::iterator mi;
	
	for(int i = max - 1; i >= 2; i--)
		for(int j = i - 1; j >= 1; j--)
			base[storage[i] - storage[j]] = make_pair(i, j);
	
	
	int n = 0;
	
	while(cin >> n && n != 0) {
		if((mi = base.find(n)) == base.end())
			cout << "No solution" << endl;
		else
			cout << mi->second.first << " " << mi->second.second << endl;
	}
	
	return 0;
}
