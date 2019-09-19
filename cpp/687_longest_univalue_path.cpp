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
class Solution {
public:
	void dfs(TreeNode* node, vector<int>& path, int len, int& res) {
		if (!root) { return; }

		dfs(node->left, path, len, res);

		if (!path.empty()) {
			if (node->val == path.back()) {
				++len;
			} else {
				len = 1;
			}
			res = max(res, len);
		}
		path.push_back(node->val);

		dfs(node->right, path, len, res);
	}

    int longestUnivaluePath(TreeNode* root) {
		vector<int> path;
		int res = INT_MIN;
		dfs(root, path, 1, res);
		return res;
    }
};

