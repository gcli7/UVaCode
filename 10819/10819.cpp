#include <algorithm>
#include <cstring>
#include <iostream>

#define BUDGET_LIMIT 10201
#define ITEM_SIZE_LIMIT 101

static const int io_setting = []() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  return 0;
}();

typedef struct {
  int price;
  int favour;
} Item;

int main() {
  int budget, item_size;
  Item items[ITEM_SIZE_LIMIT];
  int value[BUDGET_LIMIT];

  while (std::cin >> budget >> item_size) {
    if (budget > 1800) {
      budget += 200;
    }
    for (int i = 0; i < item_size; ++i) {
      std::cin >> items[i].price >> items[i].favour;
    }
    memset(value, 0, sizeof(int) * (budget + 1));

    int last_value;
    for (int i = 0; i < item_size; ++i) {
      for (int j = budget; j >= items[i].price; --j) {
        last_value = value[j - items[i].price];
        if (last_value > 0 || j == items[i].price) {
          value[j] = std::max(value[j], last_value + items[i].favour);
        }
      }
    }

    int real_budget = budget - 200, max_value = 0;
    if (real_budget > 1800 && real_budget <= 2000) {
      for (int i = 0; i <= real_budget; ++i) {
        max_value = std::max(max_value, value[i]);
      }
      for (int i = 2001; i <= budget; ++i) {
        max_value = std::max(max_value, value[i]);
      }
    } else {
      for (int i = 0; i <= budget; ++i) {
        max_value = std::max(max_value, value[i]);
      }
    }
    std::cout << max_value << "\n";
  }

  return 0;
}
