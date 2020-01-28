#include <iomanip>
#include <iostream>

#define ROW         7
#define COLUMN      8
#define BONE_LENGTH 43

int grid[ROW][COLUMN];
int result[ROW][COLUMN];
bool grid_used[ROW][COLUMN];
bool bone_used[BONE_LENGTH];
int solution_counter;

const int table[] = {1, 2, 3, 4, 5, 6, 7,
                     0, 8, 9, 10, 11, 12, 13,
                     0, 0, 14, 15, 16, 17, 18,
                     0, 0, 0, 19, 20, 21, 22,
                     0, 0, 0, 0, 23, 24, 25,
                     0, 0, 0, 0, 0, 26, 27,
                     0, 0, 0, 0, 0, 0, 28};

void display() {
  std::cout << "\n\n";
  for (auto &r : result) {
    for (auto &c : r) {
      std::cout << std::setw(4) << table[c];
    }
    std::cout << "\n";
  }
}

int get_product(const int &x, const int &y) {
  if (x <= y) {
    return x * 7 + y;
  } else {
    return y * 7 + x;
  }
}

void check_map(const int &r, const int &c) {
  if (r == 6 && c == 7 && grid_used[r][c]) {
    display();
    ++solution_counter;
    return;
  }

  if (grid_used[r][c]) {
    if (c < 7) {
      check_map(r, c + 1);
    } else {
      check_map(r + 1, 0);
    }
    return;
  }

  int rr = r + 1;
  if (rr < ROW && !grid_used[rr][c]) {
    int product = get_product(grid[r][c], grid[rr][c]);
    if (!bone_used[product]) {
      bone_used[product] = true;
      grid_used[r][c] = true;
      grid_used[rr][c] = true;
      result[r][c] = product;
      result[rr][c] = product;
      if (c < 7) {
        check_map(r, c + 1);
      } else if (r < 6) {
        check_map(r + 1, 0);
      }
      grid_used[rr][c] = false;
      grid_used[r][c] = false;
      bone_used[product] = false;
    }
  }

  int cc = c + 1;
  if (cc < COLUMN && !grid_used[r][cc]) {
    int product = get_product(grid[r][c], grid[r][cc]);
    if (!bone_used[product]) {
      bone_used[product] = true;
      grid_used[r][c] = true;
      grid_used[r][cc] = true;
      result[r][c] = product;
      result[r][cc] = product;
      if (c < 7) {
        check_map(r, c + 1);
      } else if (r < 6) {
        check_map(r + 1, 0);
      }
      grid_used[r][cc] = false;
      grid_used[r][c] = false;
      bone_used[product] = false;
    }
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int cases = 1;
  while (std::cin >> grid[0][0]) {
    if (cases != 1) {
      std::cout << "\n\n\n\n\n";
    }
    std::cout << "Layout #" << cases << ":\n\n\n";

    std::cout << std::setw(4) << grid[0][0];
    for (int j = 1; j < COLUMN; ++j) {
      std::cin >> grid[0][j];
      std::cout << std::setw(4) << grid[0][j];
    }
    for (int i = 1; i < ROW; ++i) {
      std::cout << "\n";
      for (int j = 0; j < COLUMN; ++j) {
        std::cin >> grid[i][j];
        std::cout << std::setw(4) << grid[i][j];
      }
    }
    std::cout << "\n\n";

    for (auto &r : grid_used) {
      for (auto &c : r) {
        c = false;
      }
    }
    for (auto &b : bone_used) {
      b = false;
    }
    solution_counter = 0;

    std::cout << "Maps resulting from layout #" << cases << " are:\n";
    check_map(0, 0);
    std::cout << "\n\nThere are " << solution_counter << " solution(s) for layout #" << cases << ".\n";
    ++cases;
  }

  return 0;
}
