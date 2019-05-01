/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树，求树的最大深度
// 1.直接使用递归
// 2.深度优先搜索
// 3.层序遍历，返回层数，即是最大深度
class Solution {
public:
    int maxDepth_recursive(TreeNode* root) {
       if (!root) { return 0; } 
	   return 1 + max(maxDepth_recursive(root->left), maxDepth_recursive(root->right));
    }

	void dfs(TreeNode* node, int depth, int& maxDepth) {
		if (!node) { return; }
		maxDepth = max(depth, maxDepth);

		dfs(node->left, depth+1, maxDepth);
		dfs(node->right, depth+1, maxDepth);
	}

	int maxDepth_dfs(TreeNode* root) {
		int maxDepth = 0;
		dfs(root, 1, maxDepth);
		return maxDepth;
	}

	int maxDepth_bfs(TreeNode* root) {
		if (!root) { return 0; }

		queue<TreeNode *> q;
		int maxDepth = 0;
		q.push(root);

		while(!q.empty()) {
			maxDepth++;
			auto size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();

				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}
		}

		return maxDepth;
	}
};
