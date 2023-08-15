#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1679::TwoPointers sol { };
    std::vector temp { 1, 2, 3, 4 };
    sol.maxOperations(temp, 5);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
