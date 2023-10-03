#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution199::TreeNodeBFS sol { };
    Tree tree { };
    std::vector<int> nodes { 1, 2, 3, INT_MIN, 5, INT_MIN, 4 };
    auto p_root { tree.createTree(nodes) };
    for (auto &&el: sol.rightSideView(p_root)) {
        std::cout << el << ' ';
    }
    //std::cout << sol.lowestCommonAncestor(p_root, ) << '\n';
    std::cin.ignore();
}
