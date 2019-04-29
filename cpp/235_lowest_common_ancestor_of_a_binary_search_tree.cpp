/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 和236 类似，只是这题的树是二叉搜索树，所以可以利用其性质
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (true) {
			if (root->val > max(p->val, q->val)) {
				root = root->left;
			} else if (root->val < min(p->val, q->val)) {
				root = root->right;
			} else {
				return root;
			}	
		}
    }
};
