#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution392::TwoPointers sol { };
    std::string temp { "" };
    std::string temp2 { "c" };
    sol.isSubsequence(temp, temp2);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
