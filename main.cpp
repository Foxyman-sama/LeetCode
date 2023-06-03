#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0, "");

    Solution347::DivideAndConquer sol { };
    std::vector<int> nums { 1, 1, 1, 2, 2, 3 };
    std::vector<int> nums2 { 4, 1, -1, 2, -1, 2, 3 };
    auto result { sol.topKFrequent(nums2, 2) };
    for (auto &&el : result) {
        std::cout << el << '\n';
    }

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