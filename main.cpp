#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution394::Stack sol { };
    auto result { sol.decodeString("2[20[bc]31[xy]]xd4[rt]") };
    for (auto &&el: result) {
        std::cout << el << ' ';
    }

    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
