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
        if (!head || !head->next) { return head;}
        auto dummy = new ListNode(0, head);

        unordered_map<int, ListNode *> sumMap;
        sumMap[0] = dummy;

        auto node = head;
        int sum = 0;

        while (node) {
            int val = node->val;
            sum += val;
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = node;
            } else {
                auto start = sumMap[sum]->next;
                int tmpSum = sum;
                while (start != node) {
                    tmpSum += start->val;
                    sumMap.erase(tmpSum);
                    start = start->next;
                }
                sumMap[sum]->next = node->next;
            }

            node = node->next;
        }
        return dummy->next;
    }
};
