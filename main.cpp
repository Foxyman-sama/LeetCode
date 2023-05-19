#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution66::Math sol { };
    std::vector<int> nums { 9, 9, 9 };
    nums = sol.plusOne(nums);
    for (auto &&el : nums) {
        std::cout << "#\r\t" << el << '\n';
    }

    system("pause");
}