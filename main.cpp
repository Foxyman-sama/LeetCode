#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution724::PrefixSum sol { };
    std::vector temp { 1,7,3,6,5,6 };
    sol.pivotIndex(temp);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
