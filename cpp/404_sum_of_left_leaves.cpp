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

// 返回二叉树的左叶子的和
class Solution {
public:
	void dfs(TreeNode* node, int& res, bool is_left) {
		if (!node) { return; }
		if (!node->left && !node->right && is_left) {
			res += node->val;
			return;
		}
		dfs(node->left, res, true);
		dfs(node->right, res, false);
	}

    int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		dfs(root, res, false);
		return res;
    }
};
