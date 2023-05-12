#include <iostream>
#include "leetcode.hpp"

int main() {
    Solution547::UnionFind sol { };
    Vec2D<int> vec { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    std::cout << sol.findCircleNum(vec) << '\n';
    system("pause");
}