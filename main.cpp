#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  std::string test_case { "a." };
  Solution125::TwoPointers sol { };
  sol.isPalindrome(test_case);
  system("pause");
}
