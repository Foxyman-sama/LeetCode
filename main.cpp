#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0,  "");

    Solution34::BinarySearch sol { };
    std::vector<int> nums { 1, 2, 5, 2, 3 };
    std::vector<int> nums2 { 1 };
    std::vector<int> nums3 { 5, 7, 7, 8, 8, 10 };
    auto result { sol.searchRange(nums3, 8) };
    for (auto &&el : result) {
        std::cout << el << ' ';
    }

    std::cout << '\n';
    system("pause");
}

void print(TreeNode *_p_root) noexcept {
    if (!_p_root) {
        return;
    }

    std::cout << _p_root->val << '\n';
    print(_p_root->left);
    print(_p_root->right);
}