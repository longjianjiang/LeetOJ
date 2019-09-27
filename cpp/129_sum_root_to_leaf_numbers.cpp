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

// 给定二叉树，节点数值从0-9，返回从根到叶子路径组成数字的和。
// 和之前257求从根到叶子路径的一样，递归即可
class Solution {
public:
	void dfs(TreeNode* node, vector<int>& nums, int& res) {
		nums.push_back(node->val);

		if (!node->left && !node->right) {
			string s;
			for (int num : nums) { s += to_string(num); }
			res += stoi(s);
			nums.pop_back();
			return;
		}
		if (node->left) {
			dfs(node->left, nums, res);
		}
		if (node->right) {
			dfs(node->right, nums, res);
		}
		nums.pop_back();
	}

    int sumNumbers(TreeNode* root) {
		int res = 0;
		if (!root) { return res; }
		vector<int> nums;
		dfs(root, nums, res);

		return res;
    }
};
