#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int cases = 0;
    int sides[4] = {0};

    scanf("%d", &cases);
    while(cases--) {
        for(int i = 0; i < 4; i++)
            scanf("%d", &sides[i]);

        if(sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3]) {
            printf("square\n");
            continue;
        }

        sort(sides, sides + 4);
        if(sides[0] + sides[1] + sides[2] > sides[3]) {
            if(sides[0] == sides[1] && sides[2] == sides[3])
                printf("rectangle\n");
            else
                printf("quadrangle\n");
        }
        else
            printf("banana\n");
    }

    return 0;
}