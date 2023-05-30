#include <iostream>
#include "leetcode.hpp"

void print(TreeNode *_p_root) noexcept;

int main()  {
    setlocale(0, "");
    {
        Solution67::String sol { };
        std::cout << sol.addBinary("1", "111") << '\n';
    }
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