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
 * 两两交换链表中的节点
 * 构造一个新的节点，遍历原先链表，不断添加
 * 需要处理双数时，最后节点需指向NULL
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) { return head; }

        auto res = new ListNode(-1);
        auto p = res;
        bool flag = false;
        while (head) {
            // 1-2-3-4
            /*
            -1-2-1-4-3
            */
            auto headNext = head->next;
            if (headNext) {
                auto tmp = headNext->next;
                p->next = headNext;
                headNext->next = head;
                p = head;
                head = tmp;
            } else {
                p->next = head;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            p->next = NULL;
        }
        return res->next;
    }
};
