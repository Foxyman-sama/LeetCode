#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0,  "");

    Solution2089::BinarySearch sol { };
    std::vector<int> nums { 1, 2, 5, 2, 3 };
    std::vector<int> nums2 { 1 };
    std::vector<int> nums3 {
        13, 71, 62, 30, 17, 83, 73, 56, 70,
        48, 20, 56, 4, 34, 19, 77, 54, 9,
        67, 38, 96, 71, 74, 44
    };
    auto result { sol.targetIndices(nums3, 73) };
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