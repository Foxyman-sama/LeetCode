#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution190::BitManipulation sol { };
    uint32_t bits { 10815399 };
    std::cout << sol.reverseBits(bits) << '\n';
    system("pause");
}