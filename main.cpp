#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution2352::HashTable sol { };
    std::vector<std::vector<int>> matrix { { 3,2,1 }, { 1,7,6 }, { 2,7,7 } };
    std::vector<std::vector<int>> matrix2 { { 13, 13 }, { 13, 13 } };
    std::cout << sol.equalPairs(matrix) << '\n';
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
