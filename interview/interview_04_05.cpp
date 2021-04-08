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
	bool helper(TreeNode *root, long max, long min) {
		if (!root) { return true; }
		if (root->val >= max || root->val <= min) { return false; }
		return helper(root->left, root->val, min) && helper(root->right, max, root->val);
	}

    bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MAX, LONG_MIN);
    }
};
