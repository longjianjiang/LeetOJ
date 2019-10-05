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

// 给定bst的先序，构造bst。
// 根据bst，左边小于根，右边大于根，递归的构造左右子树即可。
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.empty()) { return NULL; }
		if (preorder.size() == 1) { return new TreeNode(preorder[0]); }

		auto root = new TreeNode(preorder[0]);
		vector<int> left_preorder, right_preorder;
		for (int i = 1; i < preorder.size(); ++i) {
			if (preorder[i] < preorder[0]) {
				left_preorder.push_back(preorder[i]);
			} else {
				right_preorder.push_back(preorder[i]);
			}
		}

		root->left = bstFromPreorder(left_preorder);
		root->right = bstFromPreorder(right_preorder);

		return root;
    }
};
