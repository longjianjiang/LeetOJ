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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int nsize = inorder.size();
		if (nsize != postorder.size()) { return NULL; }
		if (nsize == 0) { return NULL; }
		auto root = new TreeNode(postorder[nsize-1]);
		if (nsize == 1) { return root; }

		vector<int> leftInorder, leftPostorder;
		vector<int> rightInorder, rightPostorder;

		bool flag = false;
		for (int i = 0; i < nsize; ++i) {
			if (inorder[i] == root->val) {
				flag = true;
			} else {
				if (!flag) {
					leftInorder.push_back(inorder[i]);
				} else {
					rightInorder.push_back(inorder[i]);
				}
			}
		}

		for (int i = 0; i < nsize-1; ++i) {
			if (leftPostorder.size() < leftInorder.size()) {
				leftPostorder.push_back(postorder[i]);
			} else {
				rightPostorder.push_back(postorder[i]);
			}
		}

		root->left = buildTree(leftInorder, leftPostorder);
		root->right = buildTree(rightInorder, rightPostorder);

		return root;
    }
};
