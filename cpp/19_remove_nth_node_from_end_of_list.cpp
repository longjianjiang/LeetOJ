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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) { return head; }

		auto p = head;
		auto q = head;
		for (int i = 0; i < n; ++i) {
			q = q->next;
		}
		if (!q) { return head->next; }

		while (q->next) {
			p = p->next;
			q = q->next;
		}
		p->next = p->next->next;

		return head;
    }
};
