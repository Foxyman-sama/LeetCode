#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution2215::HashTable sol { };
    auto result { sol.findDifference({ 1, 2, 3 }, { 2, 4, 6 }) };
    for (auto &&el: result) {
        print(el);
    }

    system("pause");
}
