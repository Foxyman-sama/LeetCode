#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0, "");
    {
        Solution215::DivideAndConquer sol { };
        std::vector<int> nums { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        std::vector<int> nums2 { 3, 2, 1, 5, 6, 4 };
        std::vector<int> nums3 { 2, 1 };
        std::vector<int> nums4 { -1, 2, 0 };
        std::cout << sol.findKthLargest(nums, 4) << '\n';
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