#ifndef LEETCODE_INPUT_HPP
#define LEETCODE_INPUT_HPP


template<typename T>
[[nodiscard]]
constexpr std::vector<T> readInput(const std::string &_k_path) noexcept {
    std::ifstream fin { _k_path };
    if (!fin.is_open()) {
        std::cerr << "This file isn`t can be opened: " << _k_path << '\n';
        return { };
    }

    constexpr size_t k_buf_size { 102'400 };
    std::vector<T> result { };
    std::string buf { };
    buf.resize(k_buf_size);
    while (fin.getline(buf.data(), k_buf_size, ' ')) {
        if constexpr (std::is_arithmetic_v<T>) {
            result.emplace_back(std::stod(buf));
        }
        else {
            result.emplace_back(buf);
        }
    }

    return result;
}
template<typename... Args>
constexpr TreeNode *createTreeNode(Args... _args) noexcept {
    
}


#endif
