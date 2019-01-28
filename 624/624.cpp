#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 25

int max_sequence[N];
int temp_sequence[N];
int track[N];
int max_sum;

void f(int limit, int times, int index, int sum, int position) {
	if(sum > times)
		return;

	if(sum > max_sum) {
		max_sum = sum;
		for(int i = 0; i < index; i++)
			max_sequence[i] = temp_sequence[i];
		max_sequence[index] = (int)'\0';
	}

	for(int i = position; i < limit; i++) {
			temp_sequence[index] = track[i];
			sum += track[i];
			f(limit, times, index + 1, sum, i + 1);
			sum -= track[i];
	}
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cd_time = 0, tracks = 0;

	while(cin >> cd_time >> tracks) {
		memset(max_sequence, '\0', sizeof(max_sequence));
		memset(temp_sequence, '\0', sizeof(temp_sequence));
		memset(track, '\0', sizeof(track));
		max_sum = 0;

		for(int i = 0; i < tracks; i++)
			cin >> track[i];

		f(tracks, cd_time, 0, 0, 0);

		for(int i = 0; max_sequence[i]; i++)
			cout << max_sequence[i] << " ";
		cout << "sum:" << max_sum << endl;
	}

	return 0;
}