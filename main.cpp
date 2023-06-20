#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"

template<
    typename T>
[[nodiscard]]
constexpr std::vector<T> readInput(const std::string &_k_path = "input.txt") noexcept;

int main() {
    setlocale(0,  "");

    Solution1237::TwoPointers sol { };
    CustomFunction fn { };
    auto result { sol.findSolution(fn, 5) };
    for (auto &&row : result) {
        for (auto &&field : row) {
            std::cout << ' ' << field;
        }

        std::cout << '\n';
    }

    system("pause");
}

template<
    typename T>
[[nodiscard]]
constexpr std::vector<T> readInput(const std::string &_k_path) noexcept {
    std::ifstream fin { _k_path };
    if (!fin.is_open()) {
        std::cerr << "It isn`t can be opened: " << _k_path << '\n';
        return { };
    }

    constexpr size_t k_buf_size { 256 };
    std::vector<T> result { };
    std::string buf { };
    buf.resize(k_buf_size);
    while ((fin.getline(buf.data(), k_buf_size, ',')) ||
           (fin.getline(buf.data(), k_buf_size, ']'))) {
        if constexpr (std::is_arithmetic_v<T>) {
            result.emplace_back(std::stod(buf));
        }
        else {
            result.emplace_back(buf);
        }
    }

    return result;
}