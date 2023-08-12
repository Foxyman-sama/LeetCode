#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution443::String sol { };
    std::vector<char> temp { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    auto result { sol.compress(temp) };
    print(result);
    system("pause");
}
