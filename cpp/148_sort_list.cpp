/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 本题让我们实现链表的排序，要求时间复杂度为O(nLogn), 所以符合要求的排序算法只有快速排序，归并排序，堆排序。
// 链表的结构比较适合归并排序，先分解，然后合并, 这个时候合并的都是有序的链表。

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if (!head || !head->next) { return head; }
    	ListNode *slow = head, *fast = head;
    	ListNode *prev = NULL;
    	while (fast && fast->next) {
    		prev = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	prev->next = NULL;
    	return merge(sortList(head), sortList(slow));
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
    	if (!l1) { return l2; }
    	if (!l2) { return l1; }
    	if (l1->val < l2->val) {
    		l1->next = merge(l1->next, l2);
    		return l1;
    	} else {
    		l2->next = merge(l1, l2->next);
    		return l2;
    	}
    }
};