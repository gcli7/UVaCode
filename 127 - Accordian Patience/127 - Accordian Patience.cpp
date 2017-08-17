#include <iostream>
#include <vector>
using namespace std;

typedef struct card {
	char num;
	char type;
} Card;

int main(int argc, char *argv[], char *evn[]) {
	string input = "";

	while(cin >> input && input != "#") {
		vector<Card> tempV;
		vector< vector<Card> > base;
		int counter = 0;

		do {
			Card temp = {input[0], input[1]};
			tempV.clear();
			tempV.push_back(temp);
			base.push_back(tempV);
			counter++;
		}
		while(counter < 52 && cin >> input);

		for(int i = 0; i < base.size(); i++) {
			if(i - 3 >= 0 && ( base[i].back().type == base[i-3].back().type || base[i].back().num == base[i-3].back().num) ) {
				base[i-3].push_back(base[i].back());
				base[i].pop_back();
				if(base[i].empty())
					base.erase(base.begin() + i);
				i = -1;
			}
			else if(i - 1 >= 0 && ( base[i].back().type == base[i-1].back().type || base[i].back().num == base[i-1].back().num) ) {
				base[i-1].push_back(base[i].back());
				base[i].pop_back();
				if(base[i].empty())
					base.erase(base.begin() + i);
				i = -1;
			}
		}
		
		if(base.size() == 1)
			cout << base.size() << " pile remaining:";
		else
			cout << base.size() << " piles remaining:";

		for(vector< vector<Card> >::iterator vi = base.begin(); vi != base.end(); vi++)
			cout << " " << (*vi).size();
		cout << endl;
	}

	return 0;
}