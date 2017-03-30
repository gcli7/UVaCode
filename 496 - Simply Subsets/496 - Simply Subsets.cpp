#include <iostream>
#include <map>
#include <sstream>
using namespace std;

void f(map<int, int> B, map<int, int> S, char a, char b) {
	bool same = true, different = false, confused = false;
	map<int, int>::iterator itM, it;
	for(itM = S.begin(); itM != S.end(); itM++)
		if((it = B.find(itM->first)) == B.end()) {
			same = false;
			different = true;
		}
		else
			confused = true;

	if(B.size() == S.size() && same && !different)
		cout << "A equals B" << endl;
	else if(!same && different && confused)
		cout << "I'm confused!" << endl;
	else if(same && !different)
		cout << b << " is a proper subset of " << a << endl;
	else
		cout << "A and B are disjoint" << endl;
}

int main(int argc, char *argv[]) {
	string s;

	while(getline(cin, s)) {
		stringstream ss;
		map<int, int> A, B;
		int i;

		ss << s;
		while(ss >> i)
			A[i] = 1;
		ss.str("");
		ss.clear();

		getline(cin, s);
		ss << s;
		while(ss >> i)
			B[i] = 1;

		if(A.size() >= B.size())
			f(A, B, 'A', 'B');
		else
			f(B, A, 'B', 'A');
	}

	return 0;
}