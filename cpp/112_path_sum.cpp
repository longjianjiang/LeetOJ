/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树和一个数，判断二叉树的从根节点到叶子节点构成的路径的val和是否等于sum
// 笔者开始的思路是找到所有从根到叶子的路径，然后进行加和判断，试了几次都有问题，
// 然后想到直接每个节点加上父节点的val，层级遍历，最后直接判断叶子节点的累加val值即可
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if (!root) { return false; }

		queue<TreeNode *> q; q.push(root);
		while (!q.empty()) {
			int nsize = (int)(q.size());
			for (int i = 0; i < nsize; ++i) {
				auto node = q.front();
				q.pop();
				if (!node->left && !node->right && node->val == sum) { return true; }
				if (node->left) {
					node->left->val += node->val;
					q.push(node->left);
				}
				if (node->right) {
					node->right->val += node->val;
					q.push(node->right);
				}	
			}
		}
        return false; 
    }

	void dfs(TreeNode* root, int target, int sum, bool& res) {
		if (!root) { return; }

		sum += root->val;

		if (!root->left && !root->right && target == sum) { res = true; }

		dfs(root->left, target, sum, res);
		dfs(root->right, target, sum, res);
	}

	bool hasPathSumRecurive(TreeNode* root, int sum) {
		bool res = false;
		dfs(root, sum, 0, res);
		return res;
	}
};
