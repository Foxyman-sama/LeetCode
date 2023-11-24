#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  auto str { "pwwkew" };
  auto str2 { "abcabcbb" };
  Solution3::SlidingWindow sol { };
  print(sol.lengthOfLongestSubstring(str));
  system("pause");
}
