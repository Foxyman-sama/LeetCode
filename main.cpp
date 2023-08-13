#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution283::TwoPointers sol { };
    std::vector temp { 0, 1, 0, 3, 12 };
    std::vector temp2 { 1, 0 };
    sol.moveZeroes(temp2);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
