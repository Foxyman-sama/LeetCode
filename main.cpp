#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution735::Stack sol { };
    std::vector<int> test_case { 10, 5, -5 };
    std::vector<int> test_case2 { 10, 2, -5 };
    std::vector<int> test_case3 { -2, 2, 1, -2 };
    auto result { sol.asteroidCollision(test_case3) };
    for (auto &&el: result) {
        std::cout << el << ' ';
    }

    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
