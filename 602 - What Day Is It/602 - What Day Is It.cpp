#include <cstdio>
#include <string>
#define N 1752
using namespace std;

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int y) {
	if(y <= N && y % 4 == 0)
		return 366;
	else if(y > N && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		return 366;
	else
		return 365;
}

bool check(int m, int d, int y) {
	if(y == N && m == 9 && d >= 3 && d <= 13)
		return true;

	if(m < 1 || m > 12 || y < 0)
		return true;

	if(y <= N && y % 4 == 0)
		day[2] = 29;
	else if(y > N && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		day[2] = 29;
	else
		day[2] = 28;

	if(d < 0 || d > day[m])
		return true;

	return false;
}

int main() {
	const char month[][10] = {"", "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December"};
	const char week[][10] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
	int m = 0, d = 0, y = 0;

	while(scanf("%d %d %d", &m, &d, &y) != EOF && !(m == 0 && d == 0 && y == 0)) {
		if(check(m, d, y)) {
			printf("%d/%d/%d is an invalid date.\n", m, d, y);
			continue;
		}

		long long int sum_day = 0;

		for(int i = 1; i < y; i++)
			sum_day += is_leap(i);

		for(int i = 1; i < m; i++)
			sum_day += day[i];

		sum_day += d;

		if(y > N || (y == N && m > 9) || (y == N && m == 9 && d >= 14))
			sum_day -= 11;

		printf("%s %d, %d is a %s\n", month[m], d, y, week[sum_day%7]);
	}

	return 0;
}