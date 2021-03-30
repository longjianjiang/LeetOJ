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

// 给定链表和k，要求返回以k作为分割的链表，小于等于k在左，大于等于在右；并不需要两边有序；
// 双指针遍历一次就好;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) { return head; }

		auto p = head, q = head;
		while (p) {
			if (p->val < x) {
				int tmp = p->val;
				p->val = q->val;
				q->val = tmp;
				q = q->next;
			}

			p = p->next;
		}

		return head;
    }
};
// 4 3 5 1 2
// 1 3 5 4 2
// 1 2 5 4 3

