#include <iostream>
#include "leetcode.hpp"

int main()  {
    Solution190::BitManipulation sol { };
    uint32_t bits { 4294967293  };
    std::cout << sol.reverseBits(bits) << '\n';
    system("pause");
}