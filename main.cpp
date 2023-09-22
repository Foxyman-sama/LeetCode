#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution437::TreeNodeDFS sol { };
    Tree tree { };
    std::vector<int> nodes { 
        10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1
    };
    auto p_root { tree.createTree(nodes) };
    sol.pathSum(p_root, 8);
    std::cin.ignore();
}
