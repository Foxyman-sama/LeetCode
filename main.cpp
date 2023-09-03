#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution649::Queue sol { };
    auto input { readInput<std::string>("input.txt") };
    std::string str { };
    for (auto &&el: input) {
        str += el;
    }

    sol.predictPartyVictory(str);

    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
