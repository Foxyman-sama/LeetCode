#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution2492::UnionFind sol  { };
    Vec2D vec { { 1, 2, 9 }, { 2, 3, 6 }, { 2, 4, 5 }, { 1, 4, 7 } };
    std::cout << sol.minScore(4, vec) << '\n';
    system("pause");
}