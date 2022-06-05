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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		int nsize = preorder.size();
		if (nsize == 0) { return NULL; }
		auto root = new TreeNode(preorder[0]);
		if (nsize == 1) { return root; }

		vector<int> left, right;
		for (int i = 1; i < nsize; ++i) {
			if (preorder[i] < root->val) {
				left.push_back(preorder[i]);
			} else {
				right.push_back(preorder[i]);
			}
		}
		root->left = bstFromPreorder(left);
		root->right = bstFromPreorder(right);

		return root;
    }
};
