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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 给定二叉树，返回每一行最大的数字。
// 层序遍历即可
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
		if (!root) { return {}; }

		int num = 1;
		queue<TreeNode *> q; q.push(root);

		vector<int> res;
		while (!q.empty()) {
			int maxNum = INT_MIN;
			vector<TreeNode *> childs;
			while (num) {
				TreeNode *node = q.front(); q.pop();
				childs.push_back(node);
				int val = node->val;
				if (val > maxNum) { maxNum = val; }
				--num;
			}

			for (auto node: childs) {
				if (node->left) { q.push(node->left); ++num; }
				if (node->right) { q.push(node->right); ++num; }
			}
			res.push_back(maxNum);
		}

		return res;
    }
};
