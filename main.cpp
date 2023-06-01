#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0, "");
    {
        Solution108::DivideAndConquer sol { };
        std::vector<int> nums { -10, -3, 0, 5, 9 };
        std::vector<int> nums2 { 1, 3 };
        std::vector<int> nums3 { 0, 1, 2, 3, 4, 5 };
        std::vector<int> nums4 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        print(sol.sortedArrayToBST(nums4));
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