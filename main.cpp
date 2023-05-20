#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution118::DynamicProgramming sol { };
    auto result { sol.generate(5) };
    for (auto &&row_el : result) {
        for (auto &&col_el : row_el) {
            std::cout << col_el << ' ';
        }
        
        std::cout << '\n';
    }

    system("pause");
}