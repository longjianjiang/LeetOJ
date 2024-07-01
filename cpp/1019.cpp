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

/*
 * 1019. 链表中的下一个更大节点
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) { return {}; }
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        int nsize = nums.size();
        vector<int> res(nsize, 0);
        stack<int> stk;
        for (int i = 0; i < nsize; ++i) {
            int tmp = nums[i];
            while (stk.empty() == false && nums[stk.top()] < tmp) {
                int idx = stk.top();
                res[idx] = tmp;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
