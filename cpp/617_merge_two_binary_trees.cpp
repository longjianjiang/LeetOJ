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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 合并二叉树，同一个节点将数值累加，不同则merge。
// 1> 递归。以左边子树进行合并，首先进行头节点的数值累加，然后判断左右，递归或者进行合并；
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		helper(t1, t2);

		return t1;
    }

	void helper(TreeNode *&t1, TreeNode *&t2) {
		if (!t1 && !t2) { return; }
		if (!t1) { t1 = t2; t2 = NULL; }
		if (!t2) { return; }

		t1->val += t2->val;
		if (t1->left) {
			if (t2->left) { helper(t1->left, t2->left); }
		} else {
			if (t2->left) { t1->left = t2->left; }
		}

		if (t1->right) {
			if (t2->right) { helper(t1->right, t2->right); }
		} else {
			if (t2->right) { t1->right = t2->right; }
		}
	}
};
