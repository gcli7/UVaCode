#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
	int cases = 0;

	scanf("%d", &cases);
	while(cases--) {
		int len = 0, num = 0, ant = 0, max_d = 0, min_d = 0;

		scanf("%d %d", &len, &num);
		while(num--) {
			scanf("%d", &ant);

			if(len - ant < ant)
				ant = len - ant;
				
			if(ant > min_d)
				min_d = ant;
			if(len - ant > max_d)
				max_d = len - ant;
		}

		printf("%d %d\n", min_d, max_d);
	}
}