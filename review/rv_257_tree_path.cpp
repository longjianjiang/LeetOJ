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
	void dfs(TreeNode *root, vector<string>& res, vector<int>& nums) {
		if (!root) { return; }

		nums.push_back(root->val);
		if (!root->left && !root->right) {
			string path = to_string(nums[0]);
			for (int i = 1; i < nums.size(); ++i) {
				path += "->"; path += to_string(nums[i]);
			}
			res.push_back(path);
			nums.pop_back();
		}
		dfs(root->left, res, nums);
		dfs(root->right, res, nums);
		nums.pop_back();
	}

    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		vector<int> nums;
		if (!root) { return res; }

		dfs(root, res, nums);

		return res;
    }
};
