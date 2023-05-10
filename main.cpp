#include "leetcode.hpp"

int main() {
    Solution1971::UnionFind test { };
    Vec2D<int> vec { { 4, 3 }, { 1, 4 }, { 4, 8 }, { 1, 7 }, { 6, 4 }, { 4, 2 }, { 7, 4 }, { 4, 0 }, { 0, 9 }, { 5, 4 } };
    test.validPath(10, vec, 5, 9);
    system("pause");
}