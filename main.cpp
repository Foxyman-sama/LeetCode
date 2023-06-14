#include <iostream>
#include "leetcode.hpp"
#include "print.hpp"

int main()  {
    setlocale(0,  "");

    Solution350::Sorting sol { };
    std::vector<int> nums1 { 1, 2, 2, 1 };
    std::vector<int> nums2 { 2, 2 };
    std::vector<int> nums3 { 4, 9, 5 };
    std::vector<int> nums4 { 9, 4, 9, 8, 4 };
    auto result { sol.intersect(nums3, nums4) };
    for (auto &&el : result) {
        std::cout << el << '\n';
    }

    system("pause");
}