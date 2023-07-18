#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution959::UnionFind sol { };
    auto result { sol.regionsBySlashes({ " /", "  " }) };
    print(result);
    system("pause");
}
