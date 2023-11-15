#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<int> positions { 10, 8, 0, 5, 3 };
  std::vector<int> speeds { 2, 4, 1, 1, 3 };
  Solution853::Stack sol { };
  print(sol.carFleet(10, positions, speeds));
  system("pause");
}
