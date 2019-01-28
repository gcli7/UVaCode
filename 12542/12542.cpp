#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define N 100005

int main(void) {
    bool prime[N] = {0};
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i < N; i++)
        if (!prime[i])
            for (int k = (N - 1) / i, j = k * i; k >= i; k--, j -= i)
                if (!prime[k])
                    prime[j] = true;

    char s[260] = {0};
    while(scanf("%s", &s) != -1 && strcmp("0", s)) {
        int max_prime = 0;
        int len = strlen(s);
        int digits = std::min(len, 5);
        char sub_s[6] = {0};

        for ( ; digits > 0; digits--) {
            int limit = len - digits;
            for (int i = 0; i <= limit; i++) {
                int value = 0;
                memset(sub_s, '\0', 5);

                for (int j = 0; j < digits; j++)
                    sub_s[j] = s[i+j];
                value = atoi(sub_s);

                if (!prime[value] && value > max_prime)
                    max_prime = value;
            }
        }
        printf("%d\n", max_prime);
    }

    return 0;
}
