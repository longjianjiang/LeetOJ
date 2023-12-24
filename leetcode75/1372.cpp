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
// 给定二叉树，寻找最长的左右左右节点路径长度，深度优先递归遍历即可。
class Solution {
public:
	int longestZigZag(TreeNode* root) {
		if (!root) { return 0; }
        if (!root->left && !root->right) { return 0;}

		int res = 1;
		dfs(root->left, true, 1, res);
		dfs(root->right, false, 1, res);

		return res;
    }

	void dfs(TreeNode *root, bool left, int depth, int& res) {
		if (!root) { return; }
        if (left) {
            if (root->right) {
                res = max(res, depth+1);
                dfs(root->right, false, depth+1, res);
            }
            dfs(root->left, true, 1, res);
        } else {
            if (root->left) {
                res = max(res, depth+1);
                dfs(root->left, true, depth+1, res);
            }
            dfs(root->right, false, 1, res);
        }
	}
};
