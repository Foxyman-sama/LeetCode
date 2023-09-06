#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution328::LinkedList sol { };
    ListNode *p_head { new ListNode { 1, new ListNode { 2,
        new ListNode { 3, new ListNode { 4, new ListNode { 5 } } } } } };

    sol.oddEvenList(p_head);
    std::cin.ignore();
}
