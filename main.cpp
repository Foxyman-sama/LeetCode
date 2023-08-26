#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1657::HashTable sol { };
    std::cout << sol.closeStrings("abc", "bca") << '\n';
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
