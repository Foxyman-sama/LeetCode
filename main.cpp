#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution27::TwoPointers sol { };
    std::vector<int> nums { 3, 2, 2, 3 };
    std::cout << sol.removeElement(nums, 3) << '\n';

    system("pause");
}