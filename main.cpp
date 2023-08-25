#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1207::HashTable sol { };
    std::vector temp { 1,2,2,1,1,3 };
    sol.uniqueOccurrences(temp);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
