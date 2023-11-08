#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::vector<std::string> test_case { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
  Solution150::Stack sol { };
  print(sol.evalRPN(test_case));
  system("pause");
}
