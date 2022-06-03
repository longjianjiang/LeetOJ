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

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int nsize = preorder.size();
		if (nsize != inorder.size()) { return NULL; }
		if (nsize == 0) { return NULL; }
		TreeNode *node = new TreeNode(preorder[0]);
		if (nsize == 1) { return node; }

		vector<int> leftPreorder, leftInorder;
		vector<int> rightPreorder, rightInorder;

		int flag = false;
		for (int i = 0; i < nsize; ++i) {
			if (inorder[i] == node->val) {
				flag = true;
			} else {
				if (!flag) {
					leftInorder.push_back(inorder[i]);
				} else {
					rightInorder.push_back(inorder[i]);
				}
			}
		}
		for (int i = 1; i < nsize; ++i) {
			if (leftPreorder.size() < leftInorder.size()) {
				leftPreorder.push_back(preorder[i]);
			} else {
				rightPreorder.push_back(preorder[i]);
			}
		}
		
		node->left = buildTree(leftPreorder, leftInorder);
		node->right = buildTree(rightPreorder, rightInorder);

		return node;
	}
};

