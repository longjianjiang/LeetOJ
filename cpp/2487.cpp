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
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) { return head; }

		vector<int> list;
		while (head) {
			if (list.empty() || head->val <= list.back()) {
				list.push_back(head->val);
			} else {
				list.pop_back();
				while (!list.empty() && list.back() < head->val) {
					list.pop_back();
				}
				list.push_back(head->val);
			}
			head = head->next;
		}
		ListNode *res = new ListNode(-1);
		auto tmp = res;
		for (auto num : list) {
			tmp->next = new ListNode(num);
			tmp = tmp->next;
		}
		return res->next;
    }
};
