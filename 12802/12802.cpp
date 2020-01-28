#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_NUMBER 1000000

void check_palindrome(const int &number, std::vector<int> &palindrome_prime) {
  std::string s = std::to_string(number);
  for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
    if (s[i] != s[j]) {
      return;
    }
  }
  palindrome_prime.emplace_back(number);
}

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  bool prime[MAX_NUMBER+1] = {false};
  std::vector<int> palindrome_prime;

  for (int i = 2; i < MAX_NUMBER; ++i) {
    if (!prime[i]) {
      for (int j = MAX_NUMBER / i, k = i * j; j >= i; --j, k -= i) {
        if (!prime[j]) {
          prime[k] = true;
        }
      }
      check_palindrome(i, palindrome_prime);
    }
  }

  int input;
  while (std::cin >> input) {
    std::cout << input * 2 << "\n";
    if (std::find(palindrome_prime.begin(), palindrome_prime.end(), input) != palindrome_prime.end()) {
      return 0;
    }
  }

  return 0;
}
