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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) { return head; }
        // if (!head->next && head->val == 0) { return NULL; }

        auto dummy = new ListNode(0, head);
        unordered_map<int, ListNode *> sumMap;
        sumMap[0] = dummy;

        auto node = head;
        int sum = 0;
        while (node) {
            sum += node->val;
            if (sumMap.find(sum) != sumMap.end()) {
                auto prev = sumMap[sum]->next;
                int cnt = sum;
                while (prev != node) {
                    cnt += prev->val;
                    sumMap.erase(cnt);
                    prev = prev->next;
                }
                sumMap[sum]->next = node->next;
            } else {
                sumMap[sum] = node;
            }
            node = node->next;
        }

        return dummy->next;
    }
};
