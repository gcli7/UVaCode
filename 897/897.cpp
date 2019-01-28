#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define N 10000000

using namespace std;

bool primes[N];
bool anagrammaticPrimes[N];

bool order(int n) {
    int last = 9;

    do {
        if(n % 10 > last)
            return false;

        last = n % 10;
        n/=10;
    }
    while(n > 0);

    return true;
}

int main(int argc, char **argv) {
    primes[0] = true;
    primes[1] = true;
    anagrammaticPrimes[0] = true;
    anagrammaticPrimes[1] = true;
    for(int i = 2; i < N; i++)
        if(!primes[i])
            for(int k = (N - 1) / i, j = i * k; k >= i; k--, j -= i)
                if(!primes[k]) {
                    primes[j] = true;
                    anagrammaticPrimes[j] = true;
                }

    vector<int> base, output;
    char buf[8] = {0};
    bool flag = true;
    int len = 0, temp = 0;

    for(int i = 2; i < N; i++)
        if(!primes[i] && order(i)) {
            flag = true;
            sprintf(buf, "%d", i);
            len = strlen(buf);

            while(next_permutation(buf, buf + len)) {
                sscanf(buf, "%d", &temp);
                if(primes[temp]) {
                    flag = false;
                    break;
                }
            }

            if(flag)
                base.push_back(i);
        }

    for(vector<int>::iterator vi = base.begin(); vi != base.end(); vi++) {
        output.push_back(*vi);
        sprintf(buf, "%d", *vi);
        len = strlen(buf);

        while(next_permutation(buf, buf + len)) {
            sscanf(buf, "%d", &temp);
            output.push_back(temp);
        }
    }
    sort(output.begin(), output.end());

	int input = 0;

	while(scanf("%d", &input) != 0 && input != 0) {
		int l = 0;
		int limit = 0;
		int display = 0;

		sprintf(buf, "%d", input);
		l = strlen(buf);
		while(l--)
			limit = limit * 10 + 9;

		for(vector<int>::iterator vi = output.begin(); *vi <= limit && vi != output.end(); vi++)
			if(*vi > input) {
				display = *vi;
				break;
			}

		printf("%d\n", display);
	}

    return 0;
}