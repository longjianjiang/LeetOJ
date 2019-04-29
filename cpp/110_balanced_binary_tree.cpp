/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树，判断是否是平衡的，即左右子树高度差不超过1
// 从底往上，如果高度超过1，直接返回
class Solution {
public:
	int dfs(TreeNode *root) {
		if (!root) { return 0; }
		if (!root->left && !root->right) { return 1; }

		auto l = dfs(root->left);
		auto r = dfs(root->right);

		if (l == -1 || r == -1) {
			return -1;
		} else {
			if (abs(l-r) > 1) {
				return -1;
			} else {
				return max(l,r) + 1;
			}
		}
	}

    bool isBalanced(TreeNode* root) {
		if (!root) { return true; }
		return dfs(root) != -1;
    }
};
