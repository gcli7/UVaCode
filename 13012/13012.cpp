#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int answer;
  while (std::cin >> answer) {
    int contestant;
    int counter = 0;

    for (int i = 0; i < 5; ++i) {
      std::cin >> contestant;
      if (contestant == answer) {
        ++counter;
      }
    }
    std::cout << counter << "\n";
  }

  return 0;
}
