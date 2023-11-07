#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<int> test_case { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  Solution42::TwoPointers sol { };
  sol.trap2(test_case);
  system("pause");
}
