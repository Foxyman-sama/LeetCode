#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution119::DynamicProgramming sol { };
    auto result { sol.getRow(3) };
    for (auto &&row_el : result) {
        std::cout << row_el << ' ';
    }

    std::cout << '\n';
    system("pause");
}