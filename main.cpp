#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution125::TwoPointers sol { };
    auto result { sol.isPalindrome("A man, a plan, a canal: Panama") };
    print(result);
    system("pause");
}
