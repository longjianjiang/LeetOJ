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

// 给定二叉搜索树(所有节点不重复)中的两个节点，返回[low, high]，区间数字的和；
// 1> 中序遍历得到有序数组，遍历求和。
// 2> 使用递归的思路，同时利用bst的性质;
// 首先判断根是否在区间[low, high]中，在的话结果加上val，其次遍历左右。
class Solution {
private:
	void helper(TreeNode *root, int low, int high, int& res) {
		if (!root) { return; }

		if (root->val <= high && root->val >= low) { res += root->val; }
		if (root->val < high) { helper(root->right, low, high, res); }
		if (root->val > low) { helper(root->left, low, high, res); }
	}
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
		int res = 0;
		helper(root, low, high, res);
		return res;
    }
};
