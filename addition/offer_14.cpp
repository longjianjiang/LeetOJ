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


// 给定链表，输出倒数k个节点；

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 1-2-3-4

// 1> 使用双指针进行前进，相距k，当right为空时，left的位置就是倒数k；
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *left = pListHead;
		ListNode *right = pListHead;
		for (int i = 0; i < k; ++i) { 
			if (!right) { return NULL; }
			right = right->next; 
		}
		if (!right) { return left; }

		while (right) {
			left = left->next;
			right = right->next;
		}
		return left;
    }
};
