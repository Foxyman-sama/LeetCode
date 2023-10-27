#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution238::PrefixAndPostfixSum sol { };
    std::vector<int> temp { 1, 2, 3, 4 };
    auto result { sol.productExceptSelf(temp) };
    print(result);
    system("pause");
}
