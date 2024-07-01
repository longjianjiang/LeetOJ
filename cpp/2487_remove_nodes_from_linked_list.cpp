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

/*
输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
		if (!head || !head->next) { return head; }

		auto dummy = new ListNode(-1, head);
		auto node = dummy;
		auto p = dummy; auto q = p->next;
		while (p && q) {
			if (q->val < p->val) {
				q = q->next;
			} else {
				node->next = q;
				node = q;
				p = node->next; q = p->next;
			}
		}

		return dummy->next;
    }
	
	ListNode* removeNodesV2(ListNode* head) {
        if (!head || !head->next) { return head; }
        vector<int> stk;
        while (head) {
            auto tmp = head->val;
            while (stk.empty() == false && stk.back() < tmp) {
                stk.pop_back();
            }
            stk.push_back(tmp);
            head = head->next;
        }
        ListNode *dummy = new ListNode(-1);
        auto node = dummy;
        while (stk.empty() == false) {
            node->next = new ListNode(stk.front());
            stk.erase(stk.begin());
            node = node->next;
        }
        return dummy->next;
    }
};
