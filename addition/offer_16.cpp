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
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 合并两个递增的链表；
// 创建新链表，依次存储即可；
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		ListNode *res = new ListNode(-1);
		ListNode *node = res;

		while (pHead1 && pHead2) {
			if (pHead1->val < pHead2->val) {
				node->next = pHead1;
				pHead1 = pHead1->next;
			} else {
				node->next = pHead2;
				pHead2 = pHead2->next;
			}
			node = node->next;
		}

		if (pHead1) { node->next = pHead1; }
		if (pHead2) { node->next = pHead2; }

		return res->next;
	}
};
