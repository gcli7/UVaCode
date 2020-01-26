#include <iostream>

int compute_time(const int &h, const int &m) {
  return h * 60 + m;
}

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int start_h, start_m, end_h, end_m;
  const int one_day_time = compute_time(24, 0);
  while (std::cin >> start_h >> start_m >> end_h >> end_m &&
         !(start_h == 0 && start_m == 0 && end_h == 0 && end_m == 0)) {
    int start_time = compute_time(start_h, start_m);
    int end_time = compute_time(end_h, end_m);
    if (start_time <= end_time) {
      std::cout << end_time - start_time << "\n";
    }
    else {
      std::cout << one_day_time - start_time + end_time << "\n";
    }
  }

  return 0;
}
