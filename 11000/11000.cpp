#include <cstdio>
#include <vector>

struct Bee {
    long int male;
    long int female;
};

using namespace std;

int main(int argc, char **argv) {
    vector<Bee> table;
    Bee last = {0, 0};
    Bee now = {0, 0};
    const long int LIMIT = 0x100000000;

    do {
        now.male = last.male + last.female;
        now.female = last.male + 1;

        table.push_back(now);

        last.male = now.male;
        last.female = now.female;
    }
    while(now.male <= LIMIT && now.female <= LIMIT);

    int input = 0;

    while(scanf("%d", &input) != 0 && input != -1)
        printf("%ld %ld\n", table[input].male, table[input].male + table[input].female);

    return 0;
}