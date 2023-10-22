#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution347::HashTable sol { };
    std::vector<int> nodes { 1, 1, 1, 2, 2, 3 };
    auto vec { sol.topKFrequent(nodes, 2) };
    print(vec);
    //std::cout << sol.lowestCommonAncestor(p_root, ) << '\n';
    std::cin.ignore();
}
