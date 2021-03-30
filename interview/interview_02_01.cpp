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
// 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//  输入：[1, 2, 3, 3, 2, 1]
//  输出：[1, 2, 3]

// 遍历一次，借助set，如果存在将其删除即可
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next) { return head; }

		unordered_set<int> us;
		ListNode *slow = NULL;
		ListNode *fast = head;
		while (fast) {
			if (us.empty() || us.find(fast->val) == us.end()) {
				us.insert(fast->val);
				slow = fast;
				fast = fast->next;
			} else {
				slow->next = fast->next;
				fast = fast->next;
			}
		}

		return head;
    }
};
