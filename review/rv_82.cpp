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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) { return head; }

        // 0-1-2-3-3-4
        // 0-1-1-1-2-2-3-4
        // 0-1-2-3-3-4-4-5
        auto tmp = new ListNode(head->val - 1);
        tmp->next = head;
        auto x = tmp;
        auto p = head, q = head->next;

        while (p && q) {
            if (p->val != q->val) {
                x = x->next;
                p = p->next;
                q = q->next;
            } else {
                while (q->next && q->next->val == p->val) {
                    q = q->next;
                }
                x->next = q->next;
                p = x->next;
                if (p) { q = p->next; }
            }
        }

        return tmp->next;
    }
};
