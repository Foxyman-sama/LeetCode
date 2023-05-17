#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution1267::UnionFind sol { };
    Vec2D<int> vecs { { 1, 0 }, { 1, 1 } };
    std::cout << sol.countServers(vecs) << '\n';
    system("pause");
}