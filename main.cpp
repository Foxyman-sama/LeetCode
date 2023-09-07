#include <iostream>
#include <fstream>
#include "leetcode.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    setlocale(0,  "");

    Solution206::LinkedList sol { };
    ListNode *p_head { new ListNode { 1, new ListNode { 2,
        new ListNode { 3, new ListNode { 4, new ListNode { 5 } } } } } };

    ListNode *p_new_head { sol.reverseList(p_head) };
    while (p_new_head != nullptr) {
        std::cout << p_new_head << " : " << p_new_head->val << '\n';
        p_new_head = p_new_head->next;
    }

    std::cin.ignore();
}
