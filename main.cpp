#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution334::Array sol { };
    std::vector<int> temp { 1, 2, 3, 4, 5 };
    auto result { sol.increasingTriplet(temp) };
    print(result);
    system("pause");
}
