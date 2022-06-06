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

/*
	2 	2
   /     \
  5 	  5
  pre: 2,5, post: 5,2
*/
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		int nsize = preorder.size();
		if (nsize == 0) { return NULL; }

		auto root = new TreeNode(preorder[0]);
		if (nsize == 1) { return root; }

		if (nsize == 2) {
			root->left = new TreeNode(preorder[1]);
			return root;
		}

		vector<int> leftPreorder, leftPostorder;
		vector<int> rightPreorder, rightPostorder;

		int leftRootVal = preorder[1];
		bool flag = false;
		for (int i = 0; i < nsize - 1; ++i) {
			if (postorder[i] != leftRootVal) {
				if (!flag) {
					leftPostorder.push_back(postorder[i]);
				} else {
					rightPostorder.push_back(postorder[i]);
				}
			} else {
				leftPostorder.push_back(postorder[i]);
				flag = true;
			}
		}

		for (int i = 1; i < nsize; ++i) {
			if (leftPreorder.size() < leftPostorder.size()) {
				leftPreorder.push_back(preorder[i]);
			} else {
				rightPreorder.push_back(preorder[i]);
			}
		}

		root->left = constructFromPrePost(leftPreorder, leftPostorder);
		root->right = constructFromPrePost(rightPreorder, rightPostorder);
		return root;
    }
};
