#include <iostream>
#include <fstream>
#include <assert.h>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
  setlocale(0, " ");

  auto str { "AABABBA" };
  auto str2 { "AAAB" };
  auto str3 { "ABBB" };
  Solution424::SlidingWindow sol { };
  print(sol.characterReplacement(str3, 2));
  system("pause");
}
