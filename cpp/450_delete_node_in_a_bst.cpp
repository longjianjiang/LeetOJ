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

// 给定key，删除bst中的这个节点
// 递归，因为无论如何删除一个节点最后总是走到一个节点，一个节点也是一颗树，所以分三种情况：
// 1. 当前节点右子树存在，这个时候返回的就是右子树，不过需要处理右子树的左子树，将原先节点的左子树添加到右节点的右子树中；
// 2. 当前节点左子树存在，这个时候直接返回左子树就可以；
// 3. 叶子节点，直接返回NULL

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) { return root; }
		if (root->val == key) {
			if (root->right) {
				auto root_left = root->left;
				auto root_right = root->right;
				if (!root_right->left) {
					root_right->left = root_left;
				} else {
					auto root_right_left = root_right->left;
					while (root_right_left->left) { root_right_left = root_right_left->left; }
					root_right_left->left = root_left;
				}
				return root_right;
			}
			if (root->left) { return root->left; }
			return NULL;
		} else if (root->val > key) {
			root->left = deleteNode(root->left, key);
		} else {
			root->right = deleteNode(root->right, key);
		}

		return root;
    }
};
