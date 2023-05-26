#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution169::DivideAndConquer2 sol { };
    std::vector<int> vec { 3, 3, 4 };
    std::cout << sol.majorityElement(vec) << '\n';
    system("pause");
}