#include <iostream>
#include <vector>

static int io = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

int main() {
    int sizeA, sizeB;
    while (std::cin >> sizeA >> sizeB && sizeA != 0 && sizeB != 0) {
        int input, result;
        std::vector<int> numsA(1), numsB(1);

        std::cin >> numsA[0];
        for (int i = 1; i < sizeA; ++i) {
            std::cin >> input;
            if (input != numsA.back()) {
                numsA.emplace_back(input);
            }
        }
        std::cin >> numsB[0];
        for (int i = 1; i < sizeB; ++i) {
            std::cin >> input;
            if (input != numsB.back()) {
                numsB.emplace_back(input);
            }
        }

        result = std::min(numsA.size(), numsB.size());
        for (int a = 0, b = 0; a < numsA.size() && b < numsB.size(); ) {
            if (numsA[a] == numsB[b]) {
                --result;
                ++a;
                ++b;
            }
            else if (numsA[a] < numsB[b]) {
                ++a;
            }
            else {
                ++b;
            }
        }
        std::cout << result << "\n";
    }

    return 0;
}