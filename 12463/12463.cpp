#include <cstdio>

int main(void) {
    long long a = 0, b = 0, c = 0, d = 0, e = 0;

    while(scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e) != -1 && a != 0)
        printf("%lld\n", a * b * c * d * d * e * e);

    return 0;
}
