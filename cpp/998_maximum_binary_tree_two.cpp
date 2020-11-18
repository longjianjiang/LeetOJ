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

// 654，给定一个数组，找到最大的作为树的根，左边数组作为左子树，右边数组作为右子树。依次类推。
// 给定一个654返回的树根节点，同时给定一个数，要求是构建树的数组末尾添加val构成新数组，根据新数组返回一个新的根节点；
// 题目中保证新数组不会出现重复数字；

// 首先处理根节点情况，然后递归的处理根节点的右子树，因为末尾添加，一定是在右子树；
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		if (!root) { return new TreeNode(val); }
		
		if (root->val < val) {
			TreeNode *node = new TreeNode(val);
			node->left = root;
			return node;
		}

		helper(root, val);

		return root;
    }

	void helper(TreeNode* root, int val) {
		TreeNode *node = new TreeNode(val);
		if (!root->right) {
			root->right = node;
			return;
		}
		if (root->right->val < val) {
			node->left = root->right;
			root->right = node;
			return;
		}
		helper(root->right, val);
	}
};
