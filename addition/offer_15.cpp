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

// 给定链表，反转后，返回首节点；
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 1> 迭代的方式；依次倒序建立新的链表：1->null => 2->1->null;
// 2> 递归的方式；将链表进行拆分成两段，首节点和剩下的一段；
class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
		ListNode *left = head;
		ListNode *right = NULL;
		while (head) {
			head = head->next;
			left->next = right;
			right = left;
			left = head;
		}

		return right;
    }

	ListNode* ReverseList_2(ListNode *head) {
		if (!head || !head->next) { return head; }

		ListNode *right = head->next;
		head->next = NULL;
		ListNode *newHead = ReverseList_2(right);
		right->next = head;

		return newHead;
	}
};
