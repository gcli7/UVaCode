#include <iostream>
#include <vector>
#include <set>

static int io = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        int size;
        std::cin >> size;

        std::vector<int> values(size);
        int counter = 0;
        for(auto &x : values) {
            std::cin >> x;
            if(x == 0) {
                ++counter;
            }
        }

        std::set<std::vector<int>> table;
        while(true) {
            table.emplace(values);
            int temp = values[0];
            counter = 0;
            for(int i = 0; i < size - 1; ++i) {
                values[i] = values[i] >= values[i+1] ? values[i] - values[i+1] : values[i+1] - values[i];
                if(values[i] == 0) {
                    ++counter;
                }
            }
            values[size-1] = values[size-1] >= temp ? values[size-1] - temp : temp - values[size-1];
            if(values[size-1] == 0) {
                ++counter;
            }

            if(counter == size) {
                std::cout << "ZERO\n";
                break;
            }
            if(table.find(values) != table.end()) {
                std::cout << "LOOP\n";
                break;
            }
        }
    }

    return 0;
}