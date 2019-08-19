#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 反转链表，首节点开始，依次将后面的指向头，完成反转。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reverse = NULL;

        auto node = head;

        while (node) {
            auto tmp = node->next;
            node->next = reverse;
            reverse = node;
            node = tmp;
        }

        return reverse;
    }
};
