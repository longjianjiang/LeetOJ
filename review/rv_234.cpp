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
    bool isPalindrome(ListNode* head) {
		if (!head || !head->next) { return true; }

		auto node = head;
		vector<int> nums;
		while (node) {
			nums.push_back(node->val);
			node = node->next;
		}
		int l = 0, r = nums.size()-1;
		while (l < r) {
			if (nums[l] != nums[r]) {
				return false;
			}
			++l; --r;
		}
		return true;
    }

	// 1-2-3
	ListNode *reverseList(ListNode *head) {
		if (!head || !head->next) { return head; }

		auto tmp = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return tmp;
	}

	ListNode *findMedium(ListNode *head) {
		if (!head || !head->next) { return head; }

		auto slow = head, fast = head->next;
		while (slow && fast) {
			slow = slow->next;
			fast = fast->next;
			if (fast) { fast = fast->next; }
		}
		return slow;
	}

	bool isPalindrome(ListNode *head) {
		if (!head || !head->next) { return true; }
		
		// 1-2-1
		// 1-2-2-1
		auto mid = findMedium(head);
		auto reverse = reverseList(mid);

		auto p = head, q = reverse;
		while (p && q) {
			if (p->val != q->val) {
				return false;
			}
			p = p->next;
			q = q->next;
		}
		return true;
	}
};
