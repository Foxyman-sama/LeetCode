#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1372::TreeNodeDFS sol { };
    Tree tree { };
    std::vector<int> nodes { 
        1, INT_MIN, 1, 1, 1, INT_MIN, INT_MIN, 1, 1,
        INT_MIN, 1, INT_MIN, INT_MIN, INT_MIN, 1
    };
    auto p_root { tree.createTree(nodes) };
    std::cout << sol.longestZigZag(p_root) << '\n';
    std::cin.ignore();
}
