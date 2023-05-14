#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution1::HashTable sol  { };
    std::vector<int> vec { 2, 7, 11, 15 };
    sol.twoSum(vec, 9);
    system("pause");
}