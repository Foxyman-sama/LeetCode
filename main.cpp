#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution605::Array sol { };
    std::vector<int> temp { 1, 0, 0, 0, 1 };
    sol.canPlaceFlowers(temp, 2);
    system("pause");
}
