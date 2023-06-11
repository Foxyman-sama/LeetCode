#ifndef LEETCODE_PRINT_HPP
#define LEETCODE_PRINT_HPP

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

#endif
