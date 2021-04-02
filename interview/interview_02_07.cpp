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

// 给定两个linked list判定是否相交，返回相交的节点；
// 1> 遍历一圈，相等的地方就是交点；
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) { return NULL; }

		auto p = headA, q = headB;
		while (p != q) {
			p = p ? p->next : headB;
			q = q ? q->next : headA;
		}
		return p;
    }
};
