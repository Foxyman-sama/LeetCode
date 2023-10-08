#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution450::BST sol { };
    Tree tree { };
    std::vector<int> nodes { 5, 3, 6, 2, 4, INT_MIN, 7 };
    auto p_root { tree.createTree(nodes) };
    sol.deleteNode(p_root, 3);
    tree.print(p_root);
    //std::cout << sol.lowestCommonAncestor(p_root, ) << '\n';
    std::cin.ignore();
}
