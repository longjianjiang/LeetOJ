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
	void dfs(TreeNode* root, int target, int sum, bool& res) {
		if (!root) { return; }
		sum += root->val;
		if (!root->left && !root->right) {
			if (sum == target) { res = true; }
		}
		
		dfs(root->left, target, sum, res);
		dfs(root->right, target, sum, res);
	}

    bool hasPathSum(TreeNode* root, int targetSum) {
		int sum = 0;
		bool res = false;

		dfs(root, targetSum, sum, res);

		return res;
    }
};
