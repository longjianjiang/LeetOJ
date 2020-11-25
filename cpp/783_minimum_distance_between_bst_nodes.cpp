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

// 给定bst，返回任意两个节点数值差值最小值。
// 1> 给了bst，一定需要使用bst的性质，所以递归的左右节点和根比较即可。
// 题目中要求的是任意节点，所以helper方法不符合条件；
// 2> 使用bst中序有序的性质，遍历一次，每次求差值，返回最小的即可。
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
		int res = INT_MAX;
		TreeNode *prev = NULL;
		dfs(root, prev, res);

		return res;
    }

	void dfs(TreeNode *root, TreeNode *& prev, int& res) {
		if (!root) { return; }

		dfs(root->left, prev, res);
		if (prev) { 
			int num = abs(root->val - prev->val);
			if (num < res) { res = num; }
		}
		prev = root;
		dfs(root->right, prev, res);
	}

	void helper(TreeNode *root, int& res) {
		if (!root) { return; }

		if (root->left) { 
			int num = root->val - root->left->val;
			if (num < res) { res = num; }
		}
		if (root->right) {
			int num = root->right->val - root->val;
			if (num < res) { res = num; }
		}
		helper(root->left, res);
		helper(root->right, res);
	}
};
