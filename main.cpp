#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution643::SlidingWindow sol { };
    std::vector temp { 1, 12, -5, -6, 50, 3 };
    std::vector temp2 { 0, 4, 0, 3, 2 };
    sol.findMaxAverage(temp, 4);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
