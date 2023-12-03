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
	vector<int> getBottomLevel(TreeNode *root) {
		if (!root) { return {}; }

		queue<TreeNode *> q;
		q.push(root);
		vector<vector<int>> res;
		while (q.empty() == false) {
			int cnt = q.size();
			vector<int> tmp;
			for (int i = 0; i < cnt; ++i) {
				auto node = q.front(); q.pop();
				tmp.push_back(node->val);
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			res.push_back(tmp);
		}
		return res.back();
	}
	vector<int> getLeafList(TreeNode *root) {
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> arr1 = getLeafList(root1);
		vector<int> arr2 = getLeafList(root2);
		return arr1 == arr2;
	}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> arr1, arr2;
		dfs(root1, arr1);
		dfs(root2, arr2);

		return arr1 == arr2;
    }

	void dfs(TreeNode *root, vector<int>& arr) {
		if (!root) { return; }
		if (!root->left && !root->right) {
			arr.push_back(root->val);
		}
		dfs(root->left, arr);
		dfs(root->right, arr);
	}
};
