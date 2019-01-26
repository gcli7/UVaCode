#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

std::vector<unsigned long long> numbers[18];

void f(char *s, int index, const int& limit) {
    if (index == limit) {
        numbers[limit].emplace_back(std::stoll(s));
        return;
    }

    s[index] = '1';
    f(s, index + 1, limit);
    s[index] = '2';
    f(s, index + 1, limit);
}


int main(void) {
    char s[17] = {0};
    for (int i = 1; i <= 17; i++)
        f(s, 0, i);

    int cases = 0;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++) {
        int digits = 0, q = 0;
        unsigned long long lower_bound = 0, upper_bound = 0, r = 0;

        printf("Case %d: ", c);
        scanf("%d %d", &digits, &q);
        r = (1 << q) - 1;

        for (std::vector<unsigned long long>::iterator vi = numbers[digits].begin(); vi != numbers[digits].end(); vi++)
            if ((unsigned long long)(*vi & r) == 0) {
                lower_bound = *vi;
                break;
            }

        if (lower_bound == 0) {
            printf("impossible\n");
            continue;
        }

        for (std::vector<unsigned long long>::reverse_iterator rvi = numbers[digits].rbegin(); *rvi >= lower_bound; rvi++)
            if ((unsigned long long)(*rvi & r) == 0) {
                upper_bound = *rvi;
                break;
            }

        if (lower_bound == upper_bound)
            printf("%lld\n", lower_bound);
        else
            printf("%lld %lld\n", lower_bound, upper_bound);
    }

    return 0;
}
