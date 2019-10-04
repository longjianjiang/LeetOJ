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

// 给定中序后序，构建二叉树。
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// 递归构建即可。

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0 && postorder.size() == 0) { return NULL; }
		if (inorder.size() == 1 && postorder.size() == 0) { return new TreeNode(inorder[0]); }

		int nsize = (int)inorder.size();
		vector<int> left_inorder, left_postorder, right_inorder, right_postorder;
		auto root = new TreeNode(postorder[nsize-1]);

		int idx = 0;
		for (int i = 0; i < nsize; ++i) {
			if (inorder[i] == postorder[nsize-1]) { idx = i; break; }
		}
		for (int i = 0; i < idx; ++i) {
			left_inorder.push_back(inorder[i]);
			left_postorder.push_back(postorder[i]);
		}
		for (int i = idx+1; i < nsize; ++i) {
			right_inorder.push_back(inorder[i]);
			right_postorder.push_back(postorder[i-1]);
		}

		root->left = buildTree(left_inorder, left_postorder);
		root->right = buildTree(right_inorder, right_postorder);

		return root;
    }
};
