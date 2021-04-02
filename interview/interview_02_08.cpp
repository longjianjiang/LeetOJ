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
// 给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode *> us;

		while (head) {
			if (us.find(head) != us.end()) { return head; }

			us.insert(head);
			head = head->next;
		}

		return NULL;
    }

	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) { return NULL; }

		auto slow = head, fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				auto p = slow;
				auto q = head;

				while (p != q) {
					p = p->next; q = q->next;
				}
				return p;
			}
		}

		return NULL;
	}
};
