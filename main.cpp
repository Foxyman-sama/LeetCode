#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution1493::SlidingWindow sol { };
    std::vector temp { 0,1,1,1,0,1,1,0,1 };
    sol.longestSubarray(temp);
    //auto result { sol.moveZeroes(temp) };
    //print(result);
    system("pause");
}
