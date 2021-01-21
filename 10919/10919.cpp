#include <iostream>
#include <unordered_set>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int pick_num, caterogy_num;
  while (std::cin >> pick_num && pick_num) {
    std::cin >> caterogy_num;

    int course;
    std::unordered_set<int> pick_courses;
    for (int i = 0; i < pick_num; ++i) {
      std::cin >> course;
      pick_courses.insert(course);
    }

    bool flag = true;
    int course_num, reqirement, hit_counter;
    for (int i = 0; i < caterogy_num; ++i) {
      std::cin >> course_num >> reqirement;
      hit_counter = 0;
      for (int j = 0; j < course_num; ++j) {
        std::cin >> course;
        if (pick_courses.find(course) != pick_courses.end()) { ++hit_counter; }
      }
      if (hit_counter < reqirement) { flag = false; }
    }

    if (flag) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }

  return 0;
}
