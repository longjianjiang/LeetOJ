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

// 给定一颗二叉树，返回所有从根到叶子的路径
// dfs，先左再右遍历每条到叶子的path，将节点拼接字符串存入数组。
class Solution {
public:
	void dfs(TreeNode *node, vector<int>& items, vector<string>& res) {
		items.push_back(node->val);
		if (!node->left && !node->right) {
			string s = to_string(items[0]);
			for (int i = 1; i < items.size(); ++i) {
				s += "->"; s += to_string(items[i]);
			}
			res.push_back(s);

			items.pop_back();
			return;
		}

		if (node->left) {
			dfs(node->left, items, res);
		}
		if (node->right) {
			dfs(node->right, items, res);
		}
		items.pop_back();
	}

    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		vector<int> items;
		if (!root) { return res; }

		dfs(root, items, res);

		return res;
    }
};
