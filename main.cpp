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
    auto str3 { "ABBB" };
    auto str4 { "AAAB" };
    Solution424::SlidingWindow sol { };
    print(sol.characterReplacement(str4, 0));
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  system("pause");
}
