#include <cstdio>

int main(void) {
    int cases = 0;
    scanf("%d\n", &cases);
    for (int t = 1; t <= cases; t++) {
        int value[100] = {0};
        int point = 0;
        char c = '\0';

        while (scanf("%c", &c) != -1 && c != '\n') {
            if (c == '+')
                value[point] != 0x0000FF ? value[point]++ : value[point] = 0x000000;
            else if (c == '-')
                value[point] != 0x000000 ? value[point]-- : value[point] = 0x0000FF;
            else if (c == '>')
                point != 99 ? point++ : point = 0;
            else if (c == '<')
                point != 0 ? point-- : point = 99;
        }
        printf("Case %d:", t);
        for (auto &x : value)
            printf(" %02X", x);
        printf("\n");
    }

    return 0;
}
