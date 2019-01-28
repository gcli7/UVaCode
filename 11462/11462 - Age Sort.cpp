#include <cstdio>
#include <algorithm>
#define N 2000005
using namespace std;

short int base[N];

int main(int argc, char **argv) {
	int people = 0;

	while(scanf("%d", &people) != -1 && people != 0) {
		for(int i = 0; i < people; i++)
			scanf("%d", &base[i]);

		sort(base, base + people);

		printf("%d", base[0]);
		for(int i = 1; i < people; i++)
			printf(" %d", base[i]);
		printf("\n");
	}

	return 0;
}