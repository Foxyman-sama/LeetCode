#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution933::Queue::RecentCounter sol { };
    sol.ping(1);
    sol.ping(100);
    sol.ping(3001);
    sol.ping(3002);

    //auto result { sol.moveZeroes(temp) };
    //print(result);
    std::cin.ignore();
}
