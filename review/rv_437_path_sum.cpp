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
class Solution {
public:
	unordered_map<int, int> dict;
	int dfs(TreeNode *root, int sum) {
		if (!root) { return 0; }
		int res = 0;
		if (root->val == sum) { ++res; }

		auto left = targetSum - root->val;
		res += dfs(root->left, left);
		res += dfs(root->right, left);

		return res;
	}

    int pathSum(TreeNode* root, int targetSum) {
		if (!root) { return 0; }
		int res = dfs(root, targetSum);
		res += pathSum(root->left, targetSum);
		res += pathSum(root->right, targetSum);

		return res;
    }

	void dfs(TreeNode *root, int targetSum, int sum, int& res) {
		if (!root) { return; }

		sum += root->val;
		int tmp = sum - targetSum;
		if (dict.find(tmp) != dict.end()) {
			res += dict[tmp];
		}
		dict[sum] += 1;
		dfs(root->left, targetSum, sum, res);
		dfs(root->right, targetSum, sum, res);
		dict[sum] -= 1;
	}

	int pathSum(TreeNode *root, int targetSum) {
		if (!root) {return 0;}

		int res = 0;
		dict[0] = 1;
		dfs(root, targetSum, 0, res);

		return res;
	}
};
