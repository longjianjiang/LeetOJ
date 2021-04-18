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
 // 给定二叉树，给出所有可能的路径和等于sum的个数；
 // 双dfs;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
		if (!root) { return 0; }

		return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

	int dfs(TreeNode *root, int sum) {
		if (!root) { return 0; }

		int res = 0;
		if (!root) { return res; }
		if (root->val == sum) { ++res; }

		int left = sum - root->val;
		res += dfs(root->left, left);
		res += dfs(root->right, left);

		return res;
	}

	// [1,null,2,null,3,null,4,null,5], 3
	// 使用回溯，case有问题。
    int pathSum(TreeNode* root, int targetSum) {
		if (!root) { return 0; }

		vector<int> chosen;
		vector<vector<int>> res;
		dfs(root, targetSum, 0, chosen, res);
		pathSum(root->left, targetSum);
		pathSum(root->right, targetSum);

		return res.size();
    }

	void dfs(TreeNode *root, int target, int sum, vector<int> chosen, vector<vector<int>>& res) {
		if (!root) { return; }
		
		sum += root->val;
		chosen.push_back(root->val);
		if (sum == target) {
			res.push_back(chosen);
		}
		dfs(root->left, target, sum, chosen, res);
		dfs(root->right, target, sum, chosen, res);
	}
};
