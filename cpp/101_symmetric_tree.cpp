/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 给定一颗二叉树，判断是否成镜像，也就是左右对称。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (!root) { return false; }
    	return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
    	if (!left && !right) { return true; }
    	if (left && !right || right && !left || left->val != right->val) { return false; }
    	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};