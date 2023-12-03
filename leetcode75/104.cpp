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
/* 二叉树最大深度
 * 1> 递归；
 * 2> 层序遍历；
 * 3> 深度优先遍历；
 */
class Solution {
public:
	void dfs(TreeNode *root, int depth, int& res) {
		if (!root) { return; }
		res = max(res, depth);
		dfs(root->left, depth+1, res);
		dfs(root->right, depth+1, res);
	}
	int maxDepthDFS(TreeNode *root) {
		int res = 0;
		dfs(root, 1, res);
		return res;
	}
	int maxDepthBFS(TreeNode* root) {
		if (!root) { return 0; }

		int res = 0;
		queue<TreeNode *> q;
		int cnt = 1;
		q.push(root);
		while (q.empty() == false) {
			for (int i = 0; i < cnt; ++i) {
				auto node = q.front();
				q.pop();
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			res += 1;
			cnt = q.size();
		}
		return res;
	}

	int maxDepthRecursive(TreeNode *root) {
        if (!root) { return 0; }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
	}
};
