#ifndef LEETCODE_DEFINITIONS_HPP
#define LEETCODE_DEFINITIONS_HPP


template<
    typename T = int>
using Vec2D = std::vector<std::vector<T>>;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
        return _x + _y;
    }
};

#endif
