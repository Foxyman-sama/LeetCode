#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1004::SlidingWindow sol { };
    std::vector temp { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    std::vector temp2 { 0, 1, 1 };
    sol.longestOnes(temp, 0);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
