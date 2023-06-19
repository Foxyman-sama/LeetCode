#ifndef LEETCODE_DEFINITIONS_HPP
#define LEETCODE_DEFINITIONS_HPP


template<
    typename T = int>
using Vec2D = std::vector<std::vector<T>>;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
        : val { }
        , left { }
        , right { } { }
    TreeNode(int _x) 
        : val { _x }
        , left { }
        , right { } { }
    TreeNode(int _x, 
             TreeNode *_p_left, 
             TreeNode *_p_right) 
        : val { _x }
        , left { _p_left }
        , right { _p_right } { }
};
class CustomFunction {
public:
    int f(int _x, 
          int _y) {
        // do something
        return 0;
    }
};

#endif
