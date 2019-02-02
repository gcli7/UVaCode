#include <cstdio>

bool f(const int &a, const int &b, const int &c, const int &sum) {
    if ((0 - a) + (0 - b) + c == sum) {
        printf("%d %d %d\n", 0 - b, 0 - a, c);
        return false;
    }
    if ((0 - a) + b + (0 - c) == sum) {
        printf("%d %d %d\n", 0 - c, 0 - a, b);
        return false;
    }
    if (a + (0 - b) + (0 - c) == sum) {
        printf("%d %d %d\n", 0 - c, 0 - b, a);
        return false;
    }
    if (a + b + c == sum) {
        printf("%d %d %d\n", a, b, c);
        return false;
    }
    return true;
}

int main(void) {
    int cases = 0;
    scanf("%d", &cases);
    while (cases--) {
        int A = 0, B = 0, C = 0;
        bool flag = true;

        scanf("%d %d %d", &A, &B, &C);
        for (int a = 1; a <= B && a + 2 <= C && flag; a++)
            for (int b = a + 1; a * b <= B && a * a + b * b + 1 <= C && flag; b++)
                for (int c = b + 1; a * b * c <= B && a * a + b * b + c * c <= C && flag; c++)
                    if (a * b * c == B && a * a + b * b + c * c == C)
                        flag = f(a, b, c, A);
        if (flag)
            printf("No solution.\n");
    }

    return 0;
}
