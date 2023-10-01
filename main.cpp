#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution236::TreeNodeDFS sol { };
    Tree tree { };
    std::vector<int> nodes { 
       3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4
    };
    auto p_root { tree.createTree(nodes) };
    auto p_node { tree.getNode(p_root, 5) };
    auto p_node2 { tree.getNode(p_root, 4) };
    sol.lowestCommonAncestor(p_root, p_node, p_node2);
    //std::cout << sol.lowestCommonAncestor(p_root, ) << '\n';
    std::cin.ignore();
}
