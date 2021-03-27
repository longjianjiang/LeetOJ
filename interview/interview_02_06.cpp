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

// 编写一个函数，检查输入的链表是否是回文的。
class Solution {
public:

	ListNode *reverseNode(ListNode *head) {
		if (!head || !head->next) { return head; }

		auto tmp = reverseNode(head->next);
		head->next->next = head;
		head->next = NULL;

		return tmp;
	}

// 1 2 3
// 1 2 3 4
    bool isPalindrome(ListNode* head) {
		if (!head || !head->next) { return true; }

		auto slow = head, fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		auto tmp = reverseNode(slow);
		while (head && tmp) {
			if (head->val != tmp->val) { return false; }
			head = head->next;
			tmp = tmp->next;
		}
		return true;
    }
};
