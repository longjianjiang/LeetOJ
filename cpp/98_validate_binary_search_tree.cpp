/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树判断是否是二叉搜索树
// 1. 二叉搜索树的中序遍历是有序的，求出中序遍历结果，如果是有序则验证通过;
// 1.1 将中序遍历的结果存储下来，如果发现节点的值小于等于last，直接返回false；
// 2. 从根开始遍历，左右满足要求，直到叶子节点; ❌ 要求满足的是节点的子树的任意节点满足要求;
// 3. 递归的方式，借助最值进行判断，二叉树的每个节点是否满足左小右大； 
class Solution {
public:
	bool dfs(TreeNode *root, long max, long min) {
		if (!root) { return true; }
		if (root->val <= min || root->val >= max) { return false; }
		return dfs(root->left, root->val, min) && dfs(root->right, max, root->val);
	}

    bool isValidBST(TreeNode* root) {
		return dfs(root, LONG_MAX, LONG_MIN);
    }

	bool isValidBSTIteration(TreeNode *root) {
		if (!root) { return true; }

		vector<int> v;
		stack<TreeNode *> s;
		auto pointer = root;

		while (!s.empty() || pointer) {
			while (pointer) {
				s.push(pointer);
				pointer = pointer->left;
			}

			auto node = s.top(); s.pop();
			if (v.empty()) {
				v.push_back(node->val);
			} else {
				int last = v.back();
				if (node->val <= last) { return false; }
				v.push_back(node->val);
			}

			pointer = node->right;
		}

		return true;
	}
};
