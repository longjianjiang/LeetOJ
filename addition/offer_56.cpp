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

// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

// 三个指针，第一个是重复节点区间的前一个节点，用来进行删除重复区间，这里需要新建一个新的链表，方便进行next操作；
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
		if (head == NULL) { return NULL; }

		auto node = new ListNode(-1); node->next = head;

		auto first = node, second = node->next, third = node->next->next;
		bool flag = false;

		while (third) {
			if (second->val == third->val) {
				flag = true;
				third = third->next;
			} else {
				if (flag) {
					first->next = third;
					second = third;
					third = third->next;

					flag = false;
				} else {
					first = first->next;
					second = second->next;
					third = third->next;
				}
			}
		}

		if (flag) {
			first->next = third;
			second = third;
			third = third->next;
		}

		return node->next;
	}
};
