#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int cases;
  int counter = 0;
  while (std::cin >> cases) {
    int cool_counter = 0;
    std::string word;
    while (cases--) {
      int different_counter = 0;
      int letter_counter['z'+1] = {0};
      bool table[31] = {false};

      std::cin >> word;
      for (const char &c : word) {
        ++letter_counter[c];
      }

      int index;
      for (index = 'a'; index <= 'z'; ++index) {
        if (letter_counter[index] != 0) {
          if (table[letter_counter[index]]) {
            break;
          }
          else {
            table[letter_counter[index]] = true;
            ++different_counter;
          }
        }
      }

      if (index > 'z' && different_counter > 1) {
        ++cool_counter;
      }
    }
    std::cout << "Case " << ++counter << ": " << cool_counter << "\n";
  }

  return 0;
}
