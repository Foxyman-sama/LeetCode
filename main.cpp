#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1448::TreeNodeDFS sol { };
    TreeNode *p_root { 
        new TreeNode { 3, 
        new TreeNode { 1, new TreeNode { 3 }, nullptr }, 
        new TreeNode { 4, new TreeNode { 1 }, new TreeNode { 5 } } } };
    auto result { sol.goodNodes(p_root) };
    std::cout << result << '\n';
    std::cin.ignore();
}
