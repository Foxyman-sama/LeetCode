#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1::HashTable sol { };
    std::vector<int> nodes { 2, 7, 11, 15 };
    std::vector<int> nodes2 { 3, 2, 4 };
    auto vec { sol.twoSum(nodes, 9) };
    print(vec);
    //std::cout << sol.lowestCommonAncestor(p_root, ) << '\n';
    std::cin.ignore();
}
