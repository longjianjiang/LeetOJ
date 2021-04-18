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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 层序遍历即可；
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
		if (!tree) { return {}; }

		vector<ListNode *> res;
		queue<TreeNode *> q;
		q.push(tree);
		int levelCnt= 1;

		while (!q.empty()) {
			auto head = new ListNode(-1);
			auto node = head;
			int cnt = 0;
			for (int i = 0; i < levelCnt; ++i) {
				auto top = q.front(); q.pop();
				if (top->left) { ++cnt; q.push(top->left); }
				if (top->right) { ++cnt; q.push(top->right); }

				node->next = new ListNode(top->val);
                node = node->next;	
			}
			res.push_back(head->next);
			levelCnt = cnt;
		}

		return res;
    }
};
