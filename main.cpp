#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<int> test_case { 73, 74, 75, 71, 69, 72, 76, 73 };
  Solution739::Stack sol { };
  print(sol.dailyTemperatures(test_case));
  system("pause");
}
