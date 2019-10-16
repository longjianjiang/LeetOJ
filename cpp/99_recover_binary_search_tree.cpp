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

// 给定一个bst，其中两个节点位置交换了，让我们进行还原，不改变树的结构。
// 1> 中序遍历，将节点存到数组，循环，交换，成为有序。
class Solution {
public:
	void inorder(TreeNode* node, vector<TreeNode *>& v) {
		if (!node) { return; }
		inorder(node->left, v);
		v.push_back(node);
		inorder(node->right, v);
	}

    void recoverTree(TreeNode* root) {
		vector<TreeNode *> v;
		inorder(root, v);

		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = 1; i < v.size(); ++i) {
				auto curr = v[i], prev = v[i-1];
				if (curr->val < prev->val) {
					flag = true;
					swap(curr->val, prev->val);
				}
			}
		}
    }
};
