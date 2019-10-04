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
// 给前序中序，还原二叉树。
// 先构建根，然后递归的构建左右子树。
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 && inorder.size() == 0) { return NULL; }
        if (preorder.size() == 1 && inorder.size() == 1) { return new TreeNode(preorder[0]); }
        
		int nsize = (int)preorder.size();
		vector<int> left_preorder, right_preorder, left_inorder, right_inorder;
		auto root = new TreeNode(preorder[0]);
		
		int idx = 0;
		for (int i = 0; i < nsize; ++i) {
			if (inorder[i] == preorder[0]) { idx = i; break; }
		}
		for (int i = 0; i < idx; ++i) {
			left_inorder.push_back(inorder[i]);
			left_preorder.push_back(preorder[i+1]);
		}
		for (int i = idx+1; i < nsize; ++i) {
			right_inorder.push_back(inorder[i]);
			right_preorder.push_back(preorder[i]);
		}


		root->left = buildTree(left_preorder, left_inorder);
		root->right = buildTree(right_preorder, right_inorder);

		return root;
    }
};
