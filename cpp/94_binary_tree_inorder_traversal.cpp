/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 迭代的方式中序遍历二叉树
// 利用递归的思路即可，使用栈来保存节点即可
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		if (!root) { return {}; }

		stack<TreeNode *> s;
		vector<int> res;
		auto pointer = root;
		while (pointer || !s.empty()) {
			while (pointer) {
				s.push(pointer);
				pointer = pointer->left;
			}

			auto node = s.top();
			s.pop();
			res.push_back(node->val);
			pointer = node->right;
		}

		return res;
    }
};
