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
    ListNode* removeZeroSumSublists(ListNode* head) {
		if (!head) { return head; }
        if (!head->next) {
            if (head->val == 0) {
                return nullptr;
            } else {
                return head;
            }
        }

		auto dummy = new ListNode(0, head);
		unordered_map<int, ListNode *> um;
		int cnt = 0;
		um[0] = dummy;

		auto node = head;
		while (node) {
			cnt += node->val;
			if (um.find(cnt) != um.end()) {
				auto prev = um[cnt];
				auto tmp = prev->next;
				auto sum = cnt;
				while (tmp != node) {
					sum += tmp->val;
					um.erase(sum);
                    tmp = tmp->next;
				}
				prev->next = node->next;
			} else {
				um[cnt] = node;
			}
			node = node->next;
		}

		return dummy->next;
    }
};
