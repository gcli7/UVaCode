#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int brief;
	int job;
} Soldier;

bool cmp(Soldier a, Soldier b) {
	if(a.job != b.job)
		return a.job > b.job;

	return a.brief > b.brief;
}

int main(int argc, char **argv) {
	int n = 0, cases = 0;

	while(scanf("%d", &n) != 0 && n) {
		Soldier s[n] = {0};

		for(int i = 0; i < n; i++)
			scanf("%d %d", &s[i].brief, &s[i].job);

		sort(s, s + n, cmp);

		int ans = s[0].brief, r = s[0].job;

		for(int i = 1; i < n; i++) {
			ans += s[i].brief;
			r -= s[i].brief;
			if(r < s[i].job)
				r = s[i].job;
		}

		printf("Case %d: %d\n", ++cases, ans + r);
	}

	return 0;
}