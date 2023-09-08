#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution2130::LinkedList sol { };
    ListNode *p_head { new ListNode { 5, new ListNode { 4,
        new ListNode { 2, new ListNode { 1 } } } } };
    ListNode *p_head2 { new ListNode { 1, new ListNode { 100000 } } };
    auto result { sol.pairSum(p_head2) };
    std::cout << result << '\n';
    std::cin.ignore();
}
