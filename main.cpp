#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");
  try {
    auto str { "AABABBA" };
    auto str2 { "BAAAB" };
    auto str3 { "ABAB" };
    auto str4 { "AAAB" };
    Solution424::SlidingWindow sol { };
    print(sol.characterReplacement(str3, 2));
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  system("pause");
}
