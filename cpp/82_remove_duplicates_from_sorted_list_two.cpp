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

// 给定链表，要求删除所有出现超过一次的节点；
// 1> 使用map记录次数，然后构建新链表；
// 2> 链表移动，构建三个节点，第一个节点删除前，第二个是遍历的节点，第三个是重复的最后一个节点；
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) { return head; }

		ListNode *tmp = new ListNode(head->val-1);
		tmp->next = head;

		ListNode *first = tmp;
		ListNode *second = tmp->next;
		ListNode *third = NULL;

		int val = 0;
		while (second) {
			val = second->val;
			auto nextNode = second->next;
			if (!nextNode) { break; }

			if (nextNode->val == val) {
				third = nextNode;
			} else {
				if (third) {
					first->next = third->next;
					third = NULL;
				} else {
					first = second;
				}
			}
			second = nextNode;
		}
		if (third) { first->next = third->next; }
		return tmp->next;
    }
};
