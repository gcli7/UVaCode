#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>

#define LIMIT 1500
#define BASE_LEN 3

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  const int base[] = {2, 3, 5};
  std::priority_queue<unsigned int, std::vector<unsigned int>,
                      std::greater<unsigned int>> ugly_nums;
  std::unordered_set<unsigned int> record;
  int counter = 1;

  ugly_nums.emplace(1);
  while (counter < LIMIT) {
    ++counter;
    for (int i = 0; i < BASE_LEN; ++i) {
      unsigned int temp = ugly_nums.top() * base[i];
      if (record.find(temp) == record.end()) {
        ugly_nums.emplace(temp);
        record.emplace(temp);
      }
    }
    ugly_nums.pop();
  }
  std::cout << "The 1500'th ugly number is " << ugly_nums.top() << ".\n";

  return 0;
}
