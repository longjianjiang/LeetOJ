/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 给定两个有序的链表，让我们将其合并
// 直接遍历，按大小依次存入新链表即可，这里可以先声明一个链表带初始节点就不需要空的判断，返回直接返回next节点即可

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *node = res;
        
        while(l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        
        if (l1) { node->next = l1; }
        if (l2) { node->next = l2; }
        
        return res->next;
    }
};