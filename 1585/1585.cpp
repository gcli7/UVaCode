#include <iostream>

#define MAX_LEN 81

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int point[MAX_LEN];
  point[0] = 0;
  for (int i = 1; i < MAX_LEN; ++i) {
    point[i] = point[i - 1] + i;
  }

  int cases;
  int counter;
  int score;
  std::string input;

  std::cin >> cases;
  while (cases--) {
    std::cin >> input;
    counter = 0;
    score = 0;
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == 'X') {
        score += point[counter];
        counter = 0;
        continue;
      }
      ++counter;
    }
    std::cout << score + point[counter] << "\n";
  }

  return 0;
}
