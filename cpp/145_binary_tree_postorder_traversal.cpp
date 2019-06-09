/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 后序遍历二叉树
// 1. 使用栈；一种简单的做法在于改变先序遍历
// 2. 不使用栈，利用节点空的左右节点来存储前驱和后继节点
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       if (!root) { return {}; } 

    }

	vector<int> postorderTraversalUsePreOrder(TreeNode *root) {
		if (!root) { return {}; }

		stack<TreeNode *> s; s.push(root);
		vector<int> res;

		while(!s.empty()) {
			auto node = s.top(); s.pop();
			res.insert(res.begin(), node->val);
			if (node->left) { s.push(node->left); }
			if (node->right) { s.push(node->right); }
		}

		return res;
	}
};
