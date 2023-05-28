#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    Solution108::DivideAndConquer sol { };
    std::vector<int> nums { -10, -3, 0, 5, 9 };
    auto p_tree { sol.sortedArrayToBST(nums) };
    print(p_tree);
    system("pause");
}

void print(TreeNode *_p_root) noexcept {
    if (_p_root) {
        std::cout << _p_root->val << '\n';
    }
    else {
        return;
    }

    print(_p_root->left);
    print(_p_root->right);
}