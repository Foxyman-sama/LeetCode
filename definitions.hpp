#ifndef LEETCODE_DEFINITIONS_HPP
#define LEETCODE_DEFINITIONS_HPP

template<typename T>
using Vec = std::vector<T>;
template<typename T = int>
using Vec2D = std::vector<std::vector<T>>;
template<typename T1, typename T2>
using VecPairs = std::vector<std::pair<T1, T2>>;


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
class List {
public:
    ListNode *createList(const std::vector<int> &_k_values) noexcept {
        if (_k_values.size() < 1) {
            return nullptr;
        }

        ListNode *p_root { new ListNode { _k_values.front() } };
        ListNode *p_it { p_root };
        for (auto it { _k_values.begin() }; it != _k_values.end(); ++it) {
            p_it->next = new ListNode { *it };
            p_it = p_it->next;
        }

        return p_root;
    }
    void print(ListNode *_p_root) noexcept {
        size_t index { };
        while (_p_root->next != nullptr) {
            std::cout  << "[" << index << "]: " << _p_root->next << '\n';
        }
    }
};

class Tree {
private:
    auto addToNode(TreeNode *_p_root, int _left_val, int _right_val) noexcept {
        std::vector<TreeNode *> nodes { };
        if (_left_val != INT_MIN) {
            TreeNode *p_left { new TreeNode { _left_val } };
            _p_root->left = p_left;
            nodes.emplace_back(p_left);
        }
        if (_right_val != INT_MIN) {
            TreeNode *p_right { new TreeNode { _right_val } };
            _p_root->right = p_right;
            nodes.emplace_back(p_right);
        }

        return nodes;
    }
    TreeNode *createTree(std::queue<int> &&_values) noexcept {
        TreeNode *p_root { new TreeNode { _values.front() } };
        _values.pop();

        std::queue<TreeNode *> nodes { };
        nodes.push(p_root);
        while (_values.empty() == false) {
            int left { _values.empty() == true ? INT_MIN : _values.front() };
            if (_values.empty() == false) {
                _values.pop();
            }

            int right { _values.empty() == true ? INT_MIN : _values.front() };
            if (_values.empty() == false) {
                _values.pop();
            }

            TreeNode *p_temp_root { nodes.front() };
            nodes.pop();

            auto left_and_right { addToNode(p_temp_root, left, right) };
            for (auto &&el: left_and_right) {
                nodes.push(el);
            }
        }

        return p_root;
    }
    void nodesValueToQueue(TreeNode *_p_root, std::queue<int> &_queue) noexcept {
        _queue.push(_p_root->val);
        if (_p_root->left != nullptr) {
            nodesValueToQueue(_p_root->left, _queue);
        } 
        if (_p_root->right != nullptr) {
            nodesValueToQueue(_p_root->right, _queue);
        }
    }

public:
    TreeNode *createTree(const std::vector<int> &_k_values) noexcept {
        std::queue<int> queue { };
        for (auto &&el: _k_values) {
            queue.emplace(el);
        }

        return createTree(std::move(queue));
    }
    void print(TreeNode *_p_root) {
        std::queue<int> queue { };
        nodesValueToQueue(_p_root, queue);
    }
};


#endif
