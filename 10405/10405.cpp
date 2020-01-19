#include <iostream>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  std::string s1, s2;
  while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
    s1 = " " + s1;
    s2 = " " + s2;
    int table[s1.size()][s2.size()];

    for (int i = 0; i < s1.size(); ++i) {
      table[i][0] = 0;
    }
    for (int i = 1; i < s2.size(); ++i) {
      table[0][i] = 0;
    }

    for (int i = 1; i < s1.size(); ++i) {
      for (int j = 1; j < s2.size(); ++j) {
        if (s1[i] == s2[j]) {
          table[i][j] = table[i-1][j-1] + 1;
        }
        else {
          table[i][j] = std::max(table[i][j-1], table[i-1][j]);
        }
      }
    }
    std::cout << table[s1.size() - 1][s2.size() - 1] << "\n";
  }

  return 0;
}
