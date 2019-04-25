/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 判断两颗二叉树的叶子节点从左到右是否相等。
// 其实就是遍历二叉树的叶子节点序列，判断是否相同即可。
// 递归和非递归方式，非递归需要使用栈来保存父节点

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {    
		vector<int> leafs_1, leafs_2;
		dfs(root1, leafs_1);
		dfs(root2, leafs_2);

		return leafs_1 == leafs_2;
    }

	void dfs(TreeNode* root, vector<int>& leafs) {
		if (!root) { return; }
		if (!root->left && !root->right) { leafs.push_back(root->val); }
		dfs(root->left, leafs);
		dfs(root->right, leafs);
	}

	void dfs_none_recursive(TreeNode *root, vector<int>& leafs) {
		if (!root) { return; }

		stack<TreeNode *> s;
		while (!s.empty() || root) {
			while (root) {
				if (!root->left && !root->right) { leafs.push_back(root->val); }
				s.push(root);
				root = root->left;
			}
			if (!s.empty()) {
				root = s.top();
				s.pop();
				root = root->right;
			}
		}
	}

};
