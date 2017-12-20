#include <iostream>
#include <map>
#include <deque>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;

	cin >> cases;
	while(cases--) {
		int candidate_num = 0, voter_num = 0;
		int votes[25] = {0};
		bool used[25] = {false};
		map<int, string> candidates;
		deque<int> voter_rank[1005];
		string s = "";

		cin >> candidate_num;
		getline(cin, s);
		for(int i = 1; i <= candidate_num; i++) {
			getline(cin, s);
			candidates[i] = s;
		}

		while(getline(cin, s) && s != "") {
			stringstream ss(s);
			int temp = 0;

			voter_num++;
			while(ss >> temp)
				voter_rank[voter_num].push_back(temp);
		}

		int candidate_counter = candidate_num, maxV = 0, maxC = 0;

		for(int i = 1; i <= voter_num; i++)
			votes[voter_rank[i].front()]++;
		for(int i = 1; i <= candidate_num; i++)
			if(votes[i] > maxV) {
				maxV = votes[i];
				maxC = i;
			}

		while((maxV << 1) <= voter_num) {
			int minV = maxV, minC = 0, min_counter = 0;

			for(int i = 1; i <= candidate_num; i++)
				if(!used[i] && votes[i] < minV) {
					minV = votes[i];
					minC = i;
					min_counter = 0;
				}
				else if(votes[i] == minV)
					min_counter++;

			if(min_counter == candidate_counter) {
				maxV = minV;
				break;
			}

			for(int i = 1; i <= candidate_num; i++)
				if(!used[i] && votes[i] == minV) {
					votes[i] = 0;
					used[i] = true;
					candidate_counter--;
				}

			for(int i = 1; i <= voter_num; i++)
				if(!voter_rank[i].empty() && used[voter_rank[i].front()]) {
					voter_rank[i].pop_front();
					while(!voter_rank[i].empty() && used[voter_rank[i].front()])
						voter_rank[i].pop_front();
					votes[voter_rank[i].front()]++;
				}

			maxV = 0;
			maxC = 0;
			for(int i = 1; i <= candidate_num; i++)
				if(!used[i] && votes[i] > maxV) {
					maxV = votes[i];
					maxC = i;
				}
		}

		for(int i = 1; i <= candidate_num; i++)
			if(!used[i] && maxV == votes[i])
				cout << candidates[i] << endl;

		if(cases)
			cout << endl;
	}

	return 0;
}