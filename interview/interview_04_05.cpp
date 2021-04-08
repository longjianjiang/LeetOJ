#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 实现一个函数，检查一棵二叉树是否为二叉搜索树。
// 中序遍历，判断是否有序即可。
class Solution {
public:
	bool helper(TreeNode *root) {
		if (!root) { return true; }
		if (!root->left && !root->right) { return true; }
		
		int top = root->val;
		if (root->left && root->left->val > top) { return false; } 
		if (root->right && root->right->val < top) { return false; }

		return helper(root->left) && helper(root->right);
	}

    bool isValidBST(TreeNode* root) {
		return helper(root);
    }
};
