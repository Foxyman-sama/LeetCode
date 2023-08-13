#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution11::TwoPointers sol { };
    std::vector temp { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    sol.maxArea(temp);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
