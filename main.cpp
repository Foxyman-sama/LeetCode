#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution872::TreeNodeDFS sol { };
    TreeNode *p_froot { new TreeNode { 1, new TreeNode { 2 },
        new TreeNode { 3 } } };
    TreeNode *p_sroot { new TreeNode { 1, new TreeNode { 3 },
        new TreeNode { 2 } } };
    TreeNode *p_froot2 { new TreeNode { 1 } };
    TreeNode *p_sroot2 { new TreeNode { 2 } };
    auto result { sol.leafSimilar(p_froot2, p_sroot2) };
    std::cout << result << '\n';
    std::cin.ignore();
}
