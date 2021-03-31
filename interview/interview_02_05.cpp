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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto res = new ListNode(-1);
		auto node = res;

		int sum = 0, carry = 0, notation = 10;
		while (l1 || l2) {
			sum = carry;
			if (l1) { sum += l1->val; l1 = l1->next; }
			if (l2) { sum += l2->val; l2 = l2->next; }

			carry = sum / notation;
			sum = sum % notation;

			node->next = new ListNode(sum);
			node = node->next;
		}
		if (carry) { node->next = new ListNode(carry); }

		return res->next;
    }
};

