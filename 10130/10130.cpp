#include <algorithm>
#include <cstring>
#include <iostream>

#define OBJECT_SIZE_LIMIT 1001
#define PERSON_SIZE_LIMIT 101
#define LOAD_LIMIT        31

static const int io_setting = []() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  return 0;
}();

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    int object_size, price[OBJECT_SIZE_LIMIT], weight[OBJECT_SIZE_LIMIT];
    int person_size, load[PERSON_SIZE_LIMIT], max_load = 0;
    int dp[OBJECT_SIZE_LIMIT][LOAD_LIMIT];
    int sum = 0;

    std::cin >> object_size;
    for (int i = 0; i < object_size; ++i) {
      std::cin >> price[i] >> weight[i];
    }
    std::cin >> person_size;
    for (int i = 0; i < person_size; ++i) {
      std::cin >> load[i];
      max_load = std::max(max_load, load[i]);
    }
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < object_size; ++i) {
      for (int j = 0; j <= max_load; ++j) {
        if (j < weight[i]) {
          dp[i+1][j] = dp[i][j];
        } else {
          dp[i+1][j] = std::max(dp[i][j], dp[i][j - weight[i]] + price[i]);
        }
      }
    }

    for (int i = 0; i < person_size; ++i) {
      sum += dp[object_size][load[i]];
    }
    std::cout << sum << "\n";
  }

  return 0;
}
