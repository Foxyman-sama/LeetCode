#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution151::TwoPointers sol { };
    std::string temp { "a good   example" };
    auto result { sol.reverseWords(temp) };
    print(result);
    system("pause");
}
