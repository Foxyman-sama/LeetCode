#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution53::DivideAndConquer sol { };
    std::vector<int> arr { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    std::vector<int> arr2 { 1 };
    std::vector<int> arr3 { 5, 4, -1, 7, 8 };
    std::cout << sol.maxSubArray(arr) << '\n';
    system("pause");
}