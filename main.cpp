#include <iostream>
#include "leetcode.hpp"

template<
    typename T>
void print(const T &_k_obj) noexcept {
    std::cout << _k_obj << '\n';
}
template<>
void print(const std::vector<int> &_k_vec) noexcept {
    for (size_t i { }; i < _k_vec.size(); ++i) {
        std::cout << i << "#\r\t" << _k_vec[i] << '\n';
    }

    std::cout << '\n';
}

int main()  {
    setlocale(0,  "");

    Solution349::BinarySearch sol { };
    std::vector<int> nums { 1, 2, 2, 1 };
    std::vector<int> nums2 { 2, 2 };
    auto result { sol.intersection(nums, nums2) };
    print(result);
    system("pause");
}