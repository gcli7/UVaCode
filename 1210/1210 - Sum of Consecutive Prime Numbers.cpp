#include <cstdio>
#include <vector>

#define N 10001

using namespace std;

int main(int argc, char **argv) {
    bool base[N] = {false};
    vector<int> prime;

    for(int i = 2; i < N; i++)
        if(!base[i]) {
            prime.push_back(i);
            for(int k = (N - 1) / i, j = i * k; k >= i; k--, j -= i)
                if(!base[k])
                    base[j] = true;
        }

    int input = 0;

    while(scanf("%d", &input) != 0 && input != 0) {
        int counter = 0;

        for(vector<int>::iterator vi = prime.begin(); vi != prime.end() && *vi <= input; vi++) {
            int sum = 0;

            for(vector<int>::iterator vj = vi; sum < input && vj != prime.end(); vj++)
                sum += *vj;

            if(sum - input == 0)
                counter++;
        }

        printf("%d\n", counter);
    }

    return 0;
}