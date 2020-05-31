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

// 给定一个二叉树，检查它是否是镜像对称的。

// 判断左右节点是否相等即可，迭代使用两个队列进行判断即可；
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (!root) { return true; }

		return helper(root->left, root->right);
    }

	bool helper(TreeNode *left, TreeNode *right) {
		if (!left && !right) { return true; }
		if (left && right) {
			if (left->val != right->val) { return false; }
			return helper(left->left, right->right) && 
				helper(left->right, right->left);
		}
		return false;
	}
};
