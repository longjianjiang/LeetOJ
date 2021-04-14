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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 删除出现超过一次的节点；
// 1-2-2-3-4-4-5
// 1-1-2-2-3
// 1-1-1
// 双指针，删除即可；
ListNode *removeDuplicates(ListNode *head) {
	if (!head || !head->next) { return head; }

	auto p = head, q = head;
	while (p && q) {
		if (p->val != q->val) {
			p = p->next;
			q = q->next;
		} else {
			while (q->next && q->next->val == p->val) {
				q = q->next;
			}
			p->next = q->next;
			q = p->next;
		}
	}

	return head;
}

// 1> 递归的思路来做；
ListNode *removeDuplicates(ListNode *head) {
	if (!head || !head->next) { return head; }

	if (head->val != head->next->val) {
		head->next = removeDuplicates(head->next);
	} else {
		auto tmp = head->next;
		while (tmp && tmp->val == head->val) {
			tmp = tmp->next;
		}
		return removeDuplicates(tmp);
	}

	return head;
}
