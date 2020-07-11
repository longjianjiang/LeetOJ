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

// 给定链表判断是否是回文；题目需要O(n)复杂度，O(1)空间；
// 1> 使用栈，遍历两次看是否一致；
// 2> 找到中间节点，一段反转，然后比较是否一致；

// 1 2 1
// 1 2 2 1
//
//
// 1-2-3
// 1-NULL
// 2-1-null
// 3-2-1-null
class Solution {
public:
	ListNode *reverseList(ListNode *head) {
		ListNode *root = NULL;
		while (head) {
			auto nextNode = head->next;
			head->next = root;
			root = head;
			head = nextNode;
		}
		return root;
	}

    bool isPalindrome(ListNode* head) {
    	if (!head) { return true; }
		auto slow = head, fast = head;
		while (fast->next) {
			if (fast->next->next) {
				fast = fast->next->next;
			} else {
				fast = fast->next;
			}
			slow = slow->next;
		}
		auto rHead = reverseList(slow);

		while (head && rHead) {
			if (head->val != rHead->val) { return false; }
			head = head->next;
			rHead = rHead->next;
		}
		return true;
    }
};
