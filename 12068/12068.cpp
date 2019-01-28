#include <cstdio>

long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void) {
    int cases = 0, stop = 0;

    scanf("%d", &stop);
    while (++cases <= stop) {
        int num = 0;
        long long int n[10] = {0};
        long long int down = 1, up = 0, temp = 0;

        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            scanf("%lld", &n[i]);
            down *= n[i];
        }

        for (int i = 0; i < num; i++)
            up += down / n[i];

        down *= num;
        temp = gcd(down, up);

        printf("Case %d: %lld/%lld\n", cases, down / temp, up / temp);
    }
    printf("\n");
}
