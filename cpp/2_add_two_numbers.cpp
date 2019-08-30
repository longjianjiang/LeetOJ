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

// 给定两个链表 2->4->3 , 5->6->4，342 + 465 = 807。返回 7->0->8
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto res = new ListNode(-1);
		auto node = res;
		int sum = 0, bit = 0;
		while (l1 && l2) {
            sum = (l1->val + l2->val + bit) % 10;
			node->next = new ListNode(sum);
			bit = (l1->val + l2->val + bit) / 10;

			l1 = l1->next;
			l2 = l2->next;
			node = node->next;
		}

		while (l1) {
			sum = (l1->val + bit) % 10;
			node->next = new ListNode(sum);
			bit = (l1->val + bit) / 10;

			l1 = l1->next;
			node = node->next;
		}
		while (l2) {
			sum = (l2->val + bit) % 10;
			node->next = new ListNode(sum);
			bit = (l2->val + bit) / 10;

			l2 = l2->next;
			node = node->next;
		}

		if (bit) {
			node->next = new ListNode(bit);
		}

		return res->next;
    }

	ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
		auto res = new ListNode(-1);
		auto node = res;

		int sum = 0, carry = 0, notation = 10;
		while (l1 || l2) {
			sum = carry;

			if (l1) { 
				sum += l1->val; 
				l1 = l1->next;
			}
			if (l2) { 
				sum += l2->val; 
				l2 = l2->next;
			}

			carry = sum / notation;
			sum %= notation;

			node->next = new ListNode(sum);
			node = node->next;
		}

		if (carry) { node->next = new ListNode(carry); }

		return res->next;
	}
};


