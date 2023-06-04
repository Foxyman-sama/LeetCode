#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0,  "");

    Solution240::BinarySearch sol { };
    Vec2D<int> vec {
        { 1, 4, 7, 11, 15 },
        { 2, 5, 8, 12, 19 },
        { 3, 6, 9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    Vec2D<int> vec2 { { -5 } };
    Vec2D<int> vec3 { { 1, 1 } };
    std::cout << sol.searchMatrix(vec2, -5) << '\n';
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