#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution509::DynamicProgramming sol { };
    print(sol.fib(10));
    system("pause");
}
