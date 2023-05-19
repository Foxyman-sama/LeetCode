#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution13::HashTable sol { };
    std::string test_case { "IV" };
    std::cout << sol.romanToInt(test_case) << '\n';
    system("pause");
}