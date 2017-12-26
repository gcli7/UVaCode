#include <cstdio>
#include <algorithm>
#define N 20005
using namespace std;

int main(int argc, char **argv) {
	int h_num = 0, k_num = 0;

	while(scanf("%d %d", &h_num, &k_num) != 0 && h_num && k_num) {
		int heads[N] = {0}, knights[N] = {0};

		for(int i = 0; i < h_num; i++)
			scanf("%d", &heads[i]);
		for(int i = 0; i < k_num; i++)
			scanf("%d", &knights[i]);

		sort(heads, heads + h_num);
		sort(knights, knights + k_num);

		int h_index = 0, answer = 0, counter = 0;

		for(int k_index = 0; k_index < k_num && h_index < h_num; k_index++)
			if(knights[k_index] >= heads[h_index]) {
				answer += knights[k_index];
				h_index++;
			}

		if(h_index >= h_num)
			printf("%d\n", answer);
		else
			printf("Loowater is doomed!\n");
	}

	return 0;
}