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

/*
1-2-3-4-5-6 
1-2-3 
6-5-4
=> 1-6-2-5-3-4

1-2-3-4-5
1-2
5-4-3
=> 1-5-2-4-3
*/
// 将链表拆分成两端，后一段反转，拼接。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

	ListNode* reverse(ListNode* head) {
		ListNode* res = NULL, *node = head;

		while (node) {
			auto tmp = node->next;
			node->next = res;
			res = node;
			node = tmp;
		}

		return res;
	}

    void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) { return; }

		auto slow = head, fast = head;
		auto l1_tail = head;
		while (fast && fast->next) {
			l1_tail = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		auto l2_head = reverse(slow);
		l1_tail->next = NULL;

	    auto node = head;
		while (node) {
			auto l1_next = node->next, l2_next = l2_head->next;

			node->next = l2_head;
			if (l1_next == NULL) {
				return;
			} else {
				l2_head->next = l1_next;
			}
			node = l1_next;
			l2_head = l2_next;
		}
    }
};

