#include <iostream>
#include "leetcode.hpp"

template<
    typename T>
void print(T _obj) noexcept;

int main()  {
    setlocale(0,  "");

    Solution349::BinarySearch sol { };
    std::vector<int> nums { 1, 2, 2, 1 };
    std::vector<int> nums2 { 2, 2 };
    print(sol.intersection(nums, nums2));
    system("pause");
}

template<
    typename T>
void print(T _obj) noexcept {
    std::cout << _obj << '\n';
}
template<>
void print(TreeNode *_p_obj) noexcept {
    if (!_p_obj) {
        return;
    }

    std::cout << _p_obj->val << '\n';
    print(_p_obj->left);
    print(_p_obj->right);
}
template<>
void print(const std::vector<int> &_k_vec) noexcept {
    for (size_t i { }; i < _k_vec.size(); ++i) {
        std::cout << i << "#\r\t" << _k_vec[i] << '\n';
    }
    
    std::cout << '\n';
}