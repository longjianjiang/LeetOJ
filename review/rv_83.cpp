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

        // 1-1-1-2-2-3-4
        auto p = head, q = head->next;
        while (p && q) {
            if (p->val == q->val) {
                while (q->next && q->next->val == p->val) {
                    q = q->next;
                }
                p->next = q->next;
                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }

        return head;
    }
};
