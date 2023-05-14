#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution2316::UnionFind sol  { };
    Vec2D<int> vec {  { 0, 2 }, { 0, 5 }, { 2, 4 }, { 1, 6 }, { 5, 4 } };
    Vec2D<int> vec2 {  { 0, 1 }, { 0, 2 }, { 1, 2 } };
    Vec2D<int> vec3 { };
    std::cout << sol.countPairs(7, vec) << '\n';
    std::cout << sol.countPairs(3, vec2) << '\n';
    system("pause");
}