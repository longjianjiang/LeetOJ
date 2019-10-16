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

// 给定二叉树，返回path（节点之间组成的path）最大值。
// 递归的左右比较即可，返回的时候则返回较长的那一边。
class Solution {
public:
    int helper(TreeNode* node, int& res) {
		if (!node) { return 0; }
		if (!node->left && !node->right) { return 0; }
		int left = 0, right = 0;
		if (node->left) {
			left = 1 + helper(node->left);
		}
		if (node->right) {
			right = 1 + helper(node->right);
		}
	
		res = max(res, left+right);
		return max(left, right);
	}

    int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		helper(root, res);
		return res;
    }
};
