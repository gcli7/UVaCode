#include <iostream>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int cases;
  std::cin >> cases;
  for (int i = 1; i <= cases; ++i) {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::cout << "Case " << i << ": "
              << (((1 + n) * n) >> 1) - ((((x << 1) + k - 1) * k) >> 1) << "\n";
  }

  return 0;
}
