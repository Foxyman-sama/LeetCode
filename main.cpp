#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution2316::UnionFind sol  { };
    Vec2D<int> vec  {  { 0, 2 }, { 0, 5 }, { 2, 4 }, { 1, 6 }, { 5, 4 } };
    std::cout << sol.countPairs(7, vec) << '\n';
    system("pause");
}