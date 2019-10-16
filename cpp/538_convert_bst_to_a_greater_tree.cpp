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

// 给定一个bst，所有节点加上比自己大的节点的和。
class Solution {
public:
	// 不成功的尝试，把问题复杂化了
    void helper(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (!root) { return; }
        if (!left && !right) { return; }

		if (right) {
            helper(right, right->left, right->right);
            auto node = right->left;
            if (!node) {
                root->val += right->val;
            } else {
                while (node->left) { node = node->left; }
                root->val += node->val;
            }
		}
        
		if (left) {
            left->val += root->val;
			helper(left, left->left, left->right);
            if (left->right) { left->right->val += root->val; }
		}
	}

	// 使用一个sum来记录当前的sum，从最右叶子开始增加，然后根左依次加，直到最左叶子
    TreeNode* convertBST(TreeNode* root) {
        if (!root) { return root; }
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        
        return root;
    }
private:
    int sum = 0;
};
