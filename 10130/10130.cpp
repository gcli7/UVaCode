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

typedef struct {
  int price;
  int weight;
} Object;

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    int object_size;
    Object objects[OBJECT_SIZE_LIMIT];
    int person_size, load[PERSON_SIZE_LIMIT], max_load = 0;
    int value[LOAD_LIMIT];
    int sum = 0;

    std::cin >> object_size;
    for (int i = 0; i < object_size; ++i) {
      std::cin >> objects[i].price >> objects[i].weight;
    }
    std::cin >> person_size;
    for (int i = 0; i < person_size; ++i) {
      std::cin >> load[i];
      max_load = std::max(max_load, load[i]);
    }
    memset(value, 0, sizeof(value));

    for (int i = 0; i < object_size; ++i) {
      for (int j = max_load; j >= 0; --j) {
        if (j >= objects[i].weight) {
          value[j] = std::max(value[j],
                              value[j - objects[i].weight] + objects[i].price);
        }
      }
    }

    for (int i = 0; i < person_size; ++i) {
      sum += value[load[i]];
    }
    std::cout << sum << "\n";
  }

  return 0;
}
