#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::string test_case { "){" };
  Solution20::Stack sol { };
  sol.isValid(test_case);
  system("pause");
}
