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
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
		if (!head || !head->next) { return head; }

		ListNode *dummy = new ListNode(0, head);
		unordered_map<int, ListNode *> dict;
		int cnt = 0;
		dict[0] = dummy;

		auto node = head;
		while (node) {
			cnt += node->val;
			if (dict.find(cnt) != dict.end()) {
				auto prev = dict[cnt];
				// remove invalid sum
				auto tmp = prev;
				int sum = cnt;
				while (tmp != node) {
					tmp = tmp->next;
					sum += tmp->val;
					if (tmp != node) {
						dict.erase(sum);
					}
				}
				prev->next = node->next;
			} else {
				dict[cnt] = node;
			}
			node = node->next;
		}
		return dummy->next;
    }
};
