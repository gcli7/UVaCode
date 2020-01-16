#include <map>
#include <iostream>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int cases = 0;
  std::cin >> cases;
  while (cases--) {
    int dna_num = 0, dna_len = 0;
    std::cin >> dna_num >> dna_len;
    std::string dna[dna_num];
    for (int i = 0; i < dna_num; ++i) {
      std::cin >> dna[i];
    }

    std::map<char, int> table[dna_len];
    for (int i = 0; i < dna_num; ++i) {
      for (int j = 0; j < dna_len; ++j) {
        ++table[j][dna[i][j]];
      }
    }

    int consensus_error = 0;
    std::string consensus_dna = "";
    for (auto &&t : table) {
      char c;
      int max_counter = 0;
      for (auto &&x : t) {
        consensus_error += x.second;
        if (x.second > max_counter) {
          max_counter = x.second;
          c = x.first;
        }
      }
      consensus_error -= max_counter;
      consensus_dna += c;
    }

    std::cout << consensus_dna << "\n";
    std::cout << consensus_error << "\n";
  }

  return 0;
}
