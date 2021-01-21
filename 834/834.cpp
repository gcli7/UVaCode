#include <iostream>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num1, num2;
  while (std::cin >> num1 >> num2) {
    bool flag = false;
    int tmp = num1 / num2;
    num1 -= tmp * num2;
    std::swap(num1, num2);
    if (num1 && num2) {
      std::cout << "[" << tmp << ";";
    } else {
      std::cout << "[" << tmp << "]\n";
      continue;
    }

    while (num1 && num2) {
      tmp = num1 / num2;
      num1 -= tmp * num2;
      std::swap(num1, num2);
      if (flag) { std::cout << ","; }
      flag = true;
      std::cout << tmp;
    }
    std::cout << "]\n";
  }
  return 0;
}
