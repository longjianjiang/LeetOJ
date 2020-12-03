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

// 链表中的下一个更大节点。题意是给一个linkedlist，请返回当前节点之后所有节点里面值最大的节点。注意最后一个节点之后因为没有其他节点了，所以返回0
// Input: [2,7,4,3,5]
// Output: [7,0,5,5,0]
// 1> 使用单调栈；
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
		if (!head) { return {}; }
		vector<int> nums;
		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}
		int nsize = nums.size();
		stack<int> stk;
		vector<int> res(nsize, 0);

		for (int i = 0; i < nsize; ++i) {
			while (!stk.empty() && nums[stk.top()] < nums[i]) {
				res[stk.top()] = nums[i];
				stk.pop();
			}
			stk.push(i);
		}

		return res;
    }
};
