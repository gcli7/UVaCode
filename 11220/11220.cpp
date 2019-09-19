#include <string>
#include <iostream>
#include <sstream>

static int io = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

int main() {
    int cases;
    std::string input;
    std::cin >> cases;
    std::getline(std::cin, input);
    std::getline(std::cin, input);

    for(int i = 1; i <= cases; ++i) {
        if(i != 1) {
            std::cout << "\n";
        }    
        std::cout << "Case #" << i << ":\n";
        std::getline(std::cin, input);
        while(input != "") {
            int counter = 0;
            std::stringstream ss(input);
            while(ss) {
                std::string str;
                ss >> str;
                if(counter < str.size()) {
                    std::cout << str[counter++];
                }
            }
            std::cout << "\n";
            std::getline(std::cin, input);
        }
    }

    return 0;
}