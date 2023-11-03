#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<int> test_case { -2, 0, 0, 2, 2 };
  Solution15::TwoPointers sol { };
  sol.threeSum(test_case);
  system("pause");
}
