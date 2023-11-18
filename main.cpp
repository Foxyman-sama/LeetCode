#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<int> heights { 2, 1, 5, 6, 2, 3 };
  Solution84::Stack sol { };
  print(sol.largestRectangleArea(heights));
  system("pause");
}
