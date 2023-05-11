#include <iostream>
#include "leetcode.hpp"

int main() {
    Solution1061::UnionFind sol { };
    std::cout << sol.smallestEquivalentString("leetcode", "programs", "sourcecode") << '\n';
    system("pause");
}