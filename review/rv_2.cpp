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

// 给定两个链表 2->4->3 , 5->6->4，342 + 465 = 807。返回 7->0->8
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2) { return NULL; }
		if (!l1) { return l2; }
		if (!l2) { return l1; }

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
			node->next = new ListNode(sum % notation);
			node = node->next;
		}
		if (carry) {
			node->next = new ListNode(carry);
		}
		return res->next;
	}
}
