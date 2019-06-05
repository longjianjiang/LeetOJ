/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 和pathSum 1和2类似，现在路径不需要从根节点到叶子节点，其中的一段即可，返回满足的路径数量
// 递归即可，每个字节点作为根节点尝试
class Solution {
public:
	void dfs(TreeNode *node, int target, bool isroot, int& res) {
		if (!node) { return; }
		int left = target - node->val;
		if (left == 0) { res++; }
		dfs(node->left, left, false, res);
		dfs(node->right, left, false, res);

		if (isroot) {
			dfs(node->left, target, true, res);
			dfs(node->right, target, true, res);
		}
	}

    int pathSum(TreeNode* root, int sum) {
     	int res = 0;
		dfs(root, sum, true, res);
		return res;
    }
};
