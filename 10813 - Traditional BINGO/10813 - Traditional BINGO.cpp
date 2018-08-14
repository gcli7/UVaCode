#include <cstdio>

#define N 5

using namespace std;

unsigned int card[N][N];
bool picked[N][N];
unsigned int bingo[75];

bool checkRow(int x) {
    for(int k = 0; k < N; k++)
        if(!picked[x][k])
            return false;

    return true;
}

bool checkCol(int y) {
    for(int k = 0; k < N; k++)
        if(!picked[k][y])
            return false;

    return true;
}

bool checkDia(int x, int y) {
    if(x == y) {
        for(int k = 0; k < N; k++)
            if(!picked[k][k])
                return false;

        return true;
    }
    else if(x + y == 4) {
        for(int k = 0; k < N; k++)
            if(!picked[k][4-k])
                return false;

        return true;
    }
    else
        return false;
}

void initialize() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            card[i][j] = 0;
            picked[i][j] = false;
        }
    picked[2][2] = true;
}

int main(int argc, char **argv) {
    unsigned int cases = 0;

    scanf("%d", &cases);
    while(cases--) {
        initialize();

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(i == 2 && j == 2)
                    continue;
                scanf("%d", &card[i][j]);
            }

        for(int i = 0; i < 75; i++)
            scanf("%d", &bingo[i]);

        unsigned int counter = 0;
        bool flag = true;
        for(counter = 0; counter < 75 && flag; counter++)
            for(int i = 0; i < N && flag; i++)
                for(int j = 0; j < N && flag; j++)
                    if(card[i][j] == bingo[counter]) {
                        picked[i][j] = true;
                        if(checkRow(i) || checkCol(j) || checkDia(i, j))
                            flag = false;
                    }

        printf("BINGO after %d numbers announced\n", counter);
    }

    return 0;
}