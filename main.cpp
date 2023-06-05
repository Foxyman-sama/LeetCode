#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0,  "");

    Solution69::BinarySearch sol { };
    std::cout << sol.mySqrt(36) << '\n';
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