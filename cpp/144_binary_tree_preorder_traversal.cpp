/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 二叉树的先序遍历
// 1. 使用栈
// 2. 借助`Threaded binary tree`，利用左右子树节点为空的来指向前驱和后继节点存储遍历的信息；
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		if (!root) { return {}; }
		
		stack<TreeNode *> s; s.push(root);
		vector<int> res;

		while(!s.empty()) {
			auto node = s.top(); s.pop();
			res.push_back(node->val);
			if (node->right) { s.push(node->right); }
			if (node->left) { s.push(node->left); }
		}

		return res;
	}

    vector<int> preorderTraversalNoStack(TreeNode* root) {
		if (!root) { return {}; }
		
		TreeNode *cur = root, *pre = NULL;
		vector<int> res;
		while(cur) {
			if (!cur->left) {
				res.push_back(cur->val);
				cur = cur->right;
			} else {
				pre = cur->left;
				while (pre->right && pre->right != cur) { pre = pre->right; }
				if (!pre->right) {
					res.push_back(cur->val);
					pre->right = cur;
					cur = cur->left;
				} else {
					pre->right = NULL;
					cur = cur->right;
				}
			}
		}

		return res;
    }
};
