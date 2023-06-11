#include <iostream>
#include "leetcode.hpp"
#include "print.hpp"

int main()  {
    setlocale(0,  "");

    Solution1365::Sorting sol { };
    std::vector<int> nums { 8, 1, 2, 2, 3 };
    print(sol.smallerNumbersThanCurrent(nums));
    system("pause");
}