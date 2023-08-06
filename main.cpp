#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution345::TwoPointers sol { };
    std::string temp { ".," };
    auto result { sol.reverseVowels(temp) };
    print(temp);
    system("pause");
}
