#include <cstdio>
#include <iostream>
using namespace std;

struct Point {
	double x;
	double y;
};

bool in_region(Point p, int a) {
	bool flag = true;
	int coordinate[8] = {0};

	coordinate[2] = a;
	coordinate[5] = a;
	coordinate[6] = a;
	coordinate[7] = a;

	for(int i = 0; flag && i < 8; i += 2) {
		if((p.x - coordinate[i]) * (p.x - coordinate[i]) + (p.y - coordinate[i+1]) * (p.y - coordinate[i+1]) > a * a)
			flag = false;
	}

	return flag;
}

int main(int argc, char **argv) {
	int N, a;

	while(scanf("%d %d", &N, &a) != EOF && N != 0) {
		Point p;
		int M = 0;

		for(int i = 0; i < N; i++) {
			scanf("%lf %lf", &p.x, &p.y);
			if(in_region(p, a))
				M++;
		}

		printf("%.5lf\n", (double)M * a * a / N);
	}

	return 0;
}