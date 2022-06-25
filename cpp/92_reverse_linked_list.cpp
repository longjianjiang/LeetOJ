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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left >= right) { return head; }
		if (!head || !head->next) { return head; }

		int cnt = 1;
		auto node = head;
		ListNode *rp = NULL, *rn = NULL;
		ListNode *rs = NULL, *re = NULL;
		while (node) {
			if (left - 1 == cnt) { rp = node; }
			if (right + 1 == cnt) { rn = node; }
			if (cnt == left) { rs = node; }
			if (cnt == right) { re = node; }
			node = node->next;
			cnt += 1;
		}
		if (!rp && !rn) {
			return reverseList(head);
		}
		// 1-2-3, 1, 2 => 2-1-3
		re->next = NULL;

		ListNode *reverseHead = rn;
		while (rs) {
			auto tmp = rs->next;
			rs->next = reverseHead;
			reverseHead = rs;
			rs = tmp;
		}
		if (rp) { rp->next = re; }
		if (left == 1) { return reverseHead; }
		return head;
    }

	ListNode *reverseList(ListNode *head) {
		if (!head || !head->next) { return head; }

		ListNode *reverseHead= NULL;
		while (head) {
			auto tmp = head->next;
			head->next = reverseHead;
			reverseHead = head;
			head = tmp;
		}

		return reverseHead;
	}
};