/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树，和两个在树中的节点，让我们求两个节点的最低公共祖先
// 首先跟当前根节点进行比较，再递归到左右节点，这个时候有四种情况，两个节点分别在左右子树，两个节点都在某一边子树，两个节点不在子树中
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) { return root; }
		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (left && right) { return root; }
		if (!right) { return left; }
		if (!left) { return right; }
		return nullptr;
    }
};
