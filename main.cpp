#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution200::UnionFind sol { };
    Vec2D<char> vecs { 
        { '1', '1', '1', '1', '0' },  
        { '1', '1', '0', '1', '0' },  
        { '1', '1', '0', '0', '0' },  
        { '0', '0', '0', '0', '0' } 
    };   
    Vec2D<char> vecs2 { 
        { '1', '0', '1', '1', '1' }, 
        { '1', '0', '1', '0', '1' }, 
        { '1', '1', '1', '0', '1' } 
    };   
    Vec2D<char> vecs3 { { '0' } };
    std::cout << sol.numIslands(vecs2) << '\n';
    system("pause");
}