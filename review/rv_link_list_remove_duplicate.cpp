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
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
		if (!head || !head->next) { return head; }

		auto p = head, q = head->next;
		//1-1-2
		while (p && q) {
			if (p->val != q->val) {
				p = p->next; q = q->next;
			} else {
				while (p->val == q->val) {
					q = q->next;
					if (!q) { break; }
				}
				p->next = q;
			}
		}

		return head;
    }
};
