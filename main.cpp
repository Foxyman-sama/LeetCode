#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");
  try {
    auto str { "ab" };
    auto str2 { "eidboaoo" };
    Solution567::SlidingWindow sol { };
    print(sol.checkInclusion(str, str2));
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  system("pause");
}
