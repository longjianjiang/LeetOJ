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
// 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
// 递归的判断左右子树高度差是否小于等于1；
class Solution {
public:
    bool isBalanced(TreeNode* root) {
		return dfs(root) != -1;
    }

	int dfs(TreeNode *root) {
		if (!root) { return 0; }
		if (!root->left && !root->right) { return 1; }

		auto left = dfs(root->left), right = dfs(root->right);
		if (left == -1 || right == -1 || abs(left-right) > 1) {
			return -1;
		} else {
			return max(left, right) + 1;
		}
	}
};
